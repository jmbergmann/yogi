#include "YogiSession.hpp"
#include "TestService.hpp"
#include "KnownTerminalsMonitor.hpp"
#include "helpers.hpp"

#include <QtDebug>
#include <QDataStream>
#include <QIODevice>

#include <yogi_core.h>

#include <memory>
using namespace std::string_literals;

#define TERMINAL_INFO_BUFFER_SIZE 1024
#define MESSAGE_BUFFER_SIZE 32 * 1024
#define KNOWN_TERMINALS_BUFFER_SIZE TERMINAL_INFO_BUFFER_SIZE * 1024


YogiSession::TerminalInfo::TerminalInfo(yogi::Leaf& leaf, yogi::terminal_type type, const char* name, yogi::Signature signature)
: terminal(yogi::Terminal::make_raw_terminal(leaf, type, name, signature))
{
}

YogiSession::BindingInfo::BindingInfo(yogi::PrimitiveTerminal& terminal, const char* targets)
: binding(terminal, targets)
{
}

QByteArray YogiSession::make_response(Status status)
{
    return QByteArray(1, status);
}

QByteArray YogiSession::to_byte_array(YogiTcpClient::ServerInformation info)
{
    QByteArray data;
    data += static_cast<char>(info.connected ? 1 : 0);
    data += info.description + '\0';
    data += info.remoteVersion + '\0';
    data += helpers::to_byte_array(info.stateChangedTime);
    return data;
}

QByteArray YogiSession::to_byte_array(YogiTcpServer::ClientInformation info)
{
    QByteArray data;
    data += static_cast<char>(info.connected ? 1 : 0);
    data += info.description + '\0';
    data += info.remoteVersion + '\0';
    data += helpers::to_byte_array(info.stateChangedTime);
    return data;
}

QByteArray YogiSession::make_connections_byte_array()
{
    QByteArray data;

    for (auto client : YogiTcpClient::instances()) {
        if (!client->enabled()) {
            continue;
        }

        data += make_idx(client);
        data += to_byte_array(client->connection());
    }

    for (auto server : YogiTcpServer::instances()) {
        auto idx = make_idx(server);
        for (auto connection : server->connections()) {
            data += idx;
            data += to_byte_array(connection);
        }
    }

    return data;
}

char YogiSession::make_idx(YogiTcpClient* client)
{
    return static_cast<char>(1 + YogiTcpClient::instances().indexOf(client));
}

char YogiSession::make_idx(YogiTcpServer* server)
{
    return static_cast<char>(1 + YogiTcpClient::instances().size() + YogiTcpServer::instances().indexOf(server));
}

template <typename Fn>
QByteArray YogiSession::use_terminal(QByteArray request, Fn fn)
{
    QDataStream stream(&request, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto terminalId = helpers::read_from_stream<unsigned>(&stream);

    {{
        QMutexLocker lock(&m_terminalLutMutex);
        auto terminalIt = m_terminalLut.find(terminalId);
        if (terminalIt == m_terminalLut.end()) {
            return make_response(RES_INVALID_TERMINAL_ID);
        }

        try {
            return fn(**terminalIt, stream);
        }
        catch(const yogi::Failure& failure) {
            return make_response(RES_API_ERROR) + QByteArray(failure.to_string().c_str());
        }
    }}
}

template <typename Terminal>
void YogiSession::create_message_observer_and_add_callback(TerminalInfo& info,
    void (YogiSession::*fn)(TerminalInfo&, const std::vector<char>&, yogi::cached_flag))
{
    auto observer = std::make_unique<yogi::MessageObserver<Terminal>>(static_cast<Terminal&>(*info.terminal));
    observer->add([&, fn](auto& payload, auto cached) {
        (this->*fn)(info, payload, cached);
    });

    info.messageObserver = std::move(observer);
    info.messageObserver->start();
}

template <typename Terminal, typename ScatteredMessage>
void YogiSession::create_message_observer_and_add_callback(TerminalInfo& info, void (YogiSession::*fn)(TerminalInfo&, ScatteredMessage&&))
{
    auto observer = std::make_unique<yogi::MessageObserver<Terminal>>(static_cast<Terminal&>(*info.terminal));
    observer->set([&, fn](auto&& msg) {
        (this->*fn)(info, std::move(msg));
    });

    info.messageObserver = std::move(observer);
    info.messageObserver->start();
}

template <typename Terminal>
yogi::Optional<std::vector<char>> YogiSession::get_cached_message(TerminalInfo& info)
{
    auto& terminal = static_cast<Terminal&>(*info.terminal);

    try {
        return {terminal.get_cached_message()};
    }
    catch (const yogi::Failure&) {
        return {};
    }
}

template <typename MessageMap>
QByteArray YogiSession::respond_to_scattered_message(MessageMap& messages, yogi::raw_operation_id opId, const QByteArray& request)
{
    auto it = messages.find(opId);
    if (it == messages.end()) {
        return make_response(RES_INVALID_OPERATION_ID);
    }

    it->second.respond(request.data() + 9, request.size() - 9);
    messages.erase(it);

    return make_response();
}

template <typename MessageMap>
QByteArray YogiSession::ignore_scattered_message(MessageMap& messages, yogi::raw_operation_id opId)
{
    auto it = messages.find(opId);
    if (it == messages.end()) {
        return make_response(RES_INVALID_OPERATION_ID);
    }

    it->second.ignore();
    messages.erase(it);

    return make_response();
}

QByteArray YogiSession::handle_version_request(const QByteArray& request)
{
    return make_response() + yogi::get_version().c_str();
}

QByteArray YogiSession::handle_current_time_request(const QByteArray& request)
{
    return make_response() + helpers::to_byte_array(std::chrono::system_clock::now());
}

QByteArray YogiSession::handle_test_command(const QByteArray& request)
{
    bool ok = false;
    if (TestService::active()) {
        ok = TestService::instance().handle_command(request.mid(1));
    }
    return make_response(ok ? RES_OK : RES_INVALID_REQUEST);
}

QByteArray YogiSession::handle_known_terminals_request(const QByteArray& request)
{
    return make_response() + KnownTerminalsMonitor::instance().get_all_terminals();
}

QByteArray YogiSession::handle_known_terminals_subtree_request(const QByteArray& request)
{
    QByteArray req(request);
    bool absolute = request[1] ? true : false;
    QString path = req.mid(2);

    return make_response() + KnownTerminalsMonitor::instance().get_terminals_subtree(path, absolute);
}

QByteArray YogiSession::handle_find_known_terminals(const QByteArray& request)
{
    QByteArray req(request);
	QDataStream stream(&req, QIODevice::ReadOnly);
	stream.skipRawData(1);

	auto caseSensitive = helpers::read_from_stream<bool>(&stream);

	QString nameSubstr = req.mid(2);

	return make_response() + KnownTerminalsMonitor::instance().get_terminals_containing(nameSubstr, !!caseSensitive);
}

QByteArray YogiSession::handle_monitor_known_terminals_request(const QByteArray& request)
{
    if (m_monitoringKnownTerminals) {
        return make_response(RES_ALREADY_MONITORING);
    }

    m_qtConnections.append(connect(&KnownTerminalsMonitor::instance(), &KnownTerminalsMonitor::known_terminals_changed,
        [=](QByteArray terminal) {
            emit(notify_client(m_socket, make_response(MON_KNOWN_TERMINALS_CHANGED) + terminal));
        }
    ));
    m_monitoringKnownTerminals = true;

    return make_response() + KnownTerminalsMonitor::instance().get_all_terminals();
}

QByteArray YogiSession::handle_connection_factories_request(const QByteArray& request)
{
    QByteArray data;

    for (auto client : YogiTcpClient::instances()) {
        if (!client->enabled()) {
            continue;
        }

        data += static_cast<char>(CFT_TCP_CLIENT);
        data += make_idx(client);
        data += helpers::to_byte_array(client->port());
        data += client->host() + '\0';
    }

    for (auto server : YogiTcpServer::instances()) {
        if (!server->enabled()) {
            continue;
        }

        data += static_cast<char>(CFT_TCP_SERVER);
        data += make_idx(server);
        data += helpers::to_byte_array(server->port());
        data += server->address() + '\0';
    }

    return make_response() + data;
}

QByteArray YogiSession::handle_connections_request(const QByteArray& request)
{
    return make_response() + make_connections_byte_array();
}

QByteArray YogiSession::handle_monitor_connections_request(const QByteArray& request)
{
    if (m_monitoringConnections) {
        return make_response(RES_ALREADY_MONITORING);
    }

    for (auto client : YogiTcpClient::instances()) {
        m_qtConnections.append(connect(client, &YogiTcpClient::connection_changed, [=](YogiTcpClient::ServerInformation info) {
            QByteArray data;
            data += make_idx(client);
            data += to_byte_array(info);
            emit(notify_client(m_socket, make_response(MON_CONNECTION_CHANGED) + data));
        }));
    }

    for (auto server : YogiTcpServer::instances()) {
        m_qtConnections.append(connect(server, &YogiTcpServer::connection_changed, [=](std::shared_ptr<yogi::TcpConnection>, YogiTcpServer::ClientInformation info) {
            QByteArray data;
            data += make_idx(server);
            data += to_byte_array(info);
            emit(notify_client(m_socket, make_response(MON_CONNECTION_CHANGED) + data));
        }));
    }

    m_monitoringConnections = true;

    return make_response() + make_connections_byte_array();
}

QByteArray YogiSession::handle_client_address_request(const QByteArray& request)
{
    auto addr = m_socket->peerAddress().toString();
    return make_response() + helpers::to_byte_array(addr);
}

QByteArray YogiSession::handle_dns_lookup_request(const QByteArray& request)
{
	if (request.size() < 2 || request[request.size() - 1] != '\0') {
		return make_response(RES_INVALID_REQUEST);
	}

	int id = QHostInfo::lookupHost(request.mid(1), this, SLOT(on_dns_lookup_finished(QHostInfo)));

	return make_response() + helpers::to_byte_array(id);
}

QByteArray YogiSession::handle_create_terminal_request(const QByteArray& request)
{
    if (request.size() < 7 || request[request.size() - 1] != '\0') {
        return make_response(RES_INVALID_REQUEST);
    }

    QByteArray req(request);
    QDataStream stream(&req, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto type      = helpers::read_from_stream<yogi::terminal_type>(&stream);
    auto signature = helpers::read_from_stream<yogi::Signature>(&stream);

    if (type > yogi::CLIENT) {
        return make_response(RES_INVALID_TERMINAL_TYPE);
    }

    YOGI_LOG_DEBUG(m_logger, "Creating Terminal " << type << " '" << (req.constData() + 6) << "' [" << signature << "]...");

    auto info = std::make_shared<TerminalInfo>(m_leaf, type, req.constData() + 6, signature);

    QMutexLocker lock(&m_terminalLutMutex);
    auto id = ++m_lastTerminalId;
    info->id = id;
    m_terminalLut.insert(id, info);

    return make_response() + helpers::to_byte_array(id);
}

QByteArray YogiSession::handle_destroy_terminal_request(const QByteArray& request)
{
    QByteArray req(request);
    QDataStream stream(&req, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto id = helpers::read_from_stream<unsigned>(&stream);

    {{
        QMutexLocker lock(&m_terminalLutMutex);
        auto terminalIt = m_terminalLut.find(id);
        if (terminalIt == m_terminalLut.end()) {
            return make_response(RES_INVALID_TERMINAL_ID);
        }

        m_terminalLut.erase(terminalIt);
    }}

    return make_response();
}

QByteArray YogiSession::handle_create_binding_request(const QByteArray& request)
{
    if (request.size() < 7 || request[request.size() - 1] != '\0') {
        return make_response(RES_INVALID_REQUEST);
    }

    QByteArray req(request);
    QDataStream stream(&req, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto terminalId = helpers::read_from_stream<unsigned>(&stream);

    std::shared_ptr<BindingInfo> info;
    {{
        QMutexLocker lock(&m_terminalLutMutex);

        auto terminalIt = m_terminalLut.find(terminalId);
        if (terminalIt == m_terminalLut.end()) {
            return make_response(RES_INVALID_TERMINAL_ID);
        }

        auto terminal = dynamic_cast<yogi::PrimitiveTerminal*>(&*(*terminalIt)->terminal);
        if (terminal == nullptr) {
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        YOGI_LOG_DEBUG(m_logger, "Creating Binding from Terminal " << terminal->type() << " '" << terminal->name()
            << "' [" << terminal->signature() << "] to '" << (req.constData() + 5) << "'...");

        info = std::make_shared<BindingInfo>(*terminal, req.constData() + 5);
    }}

    QMutexLocker lock(&m_bindingLutMutex);
    auto id = ++m_lastBindingId;
    info->id = id;
    m_bindingLut.insert(id, info);

    return make_response() + helpers::to_byte_array(m_lastBindingId);
}

QByteArray YogiSession::handle_destroy_binding_request(const QByteArray& request)
{
    QByteArray req(request);
    QDataStream stream(&req, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto id = helpers::read_from_stream<unsigned>(&stream);

    {{
        QMutexLocker lock(&m_bindingLutMutex);

        auto bindingIt = m_bindingLut.find(id);
        if (bindingIt == m_bindingLut.end()) {
            return make_response(RES_INVALID_BINDING_ID);
        }

        m_bindingLut.erase(bindingIt);
    }}

    return make_response();
}

QByteArray YogiSession::handle_monitor_binding_state_request(const QByteArray& request)
{
    QByteArray req(request);
    QDataStream stream(&req, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto id = helpers::read_from_stream<unsigned>(&stream);

    {{
        QMutexLocker lock(&m_bindingLutMutex);

        auto bindingIt = m_bindingLut.find(id);
        if (bindingIt == m_bindingLut.end()) {
            return make_response(RES_INVALID_BINDING_ID);
        }

        const auto& info = *bindingIt;
        if (info->observer) {
            return make_response(RES_ALREADY_MONITORING);
        }

        info->observer = std::make_unique<yogi::BindingObserver>(info->binding);
        info->observer->add([this, info = &*info](auto state) {
            this->on_binding_state_changed(*info, state);
        });
        info->observer->start();
    }}

    return make_response();
}

QByteArray YogiSession::handle_monitor_builtin_binding_state_request(const QByteArray& request)
{
    QByteArray req(request);
	QDataStream stream(&req, QIODevice::ReadOnly);
	stream.skipRawData(1);

    auto id = helpers::read_from_stream<unsigned>(&stream);

	{{
		QMutexLocker lock(&m_terminalLutMutex);

		auto terminalIt = m_terminalLut.find(id);
		if (terminalIt == m_terminalLut.end()) {
			return make_response(RES_INVALID_TERMINAL_ID);
		}

        const auto& info = *terminalIt;
		if (info->bindingObserver) {
			return make_response(RES_ALREADY_MONITORING);
		}

        auto terminal = dynamic_cast<yogi::Binder*>(&*info->terminal);
        if (terminal == nullptr) {
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        info->bindingObserver = std::make_unique<yogi::BindingObserver>(*terminal);
        info->bindingObserver->add([this, info = &*info](auto state) {
            this->on_builtin_binding_state_changed(*info, state);
        });
        info->bindingObserver->start();
	}}

	return make_response();
}

QByteArray YogiSession::handle_monitor_subscription_state_request(const QByteArray& request)
{
    QByteArray req(request);
    QDataStream stream(&req, QIODevice::ReadOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream.skipRawData(1);

    auto id = helpers::read_from_stream<unsigned>(&stream);

    {{
        QMutexLocker lock(&m_terminalLutMutex);

        auto terminalIt = m_terminalLut.find(id);
        if (terminalIt == m_terminalLut.end()) {
            return make_response(RES_INVALID_TERMINAL_ID);
        }

        const auto& info = *terminalIt;
        if (info->subscriptionObserver) {
            return make_response(RES_ALREADY_MONITORING);
        }

        auto terminal = dynamic_cast<yogi::Subscribable*>(&*info->terminal);
        if (terminal == nullptr) {
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        info->subscriptionObserver = std::make_unique<yogi::SubscriptionObserver>(*terminal);
        info->subscriptionObserver->add([this, info = &*info](auto state) {
            this->on_subscription_state_changed(*info, state);
        });
        info->subscriptionObserver->start();
    }}

    return make_response();
}

QByteArray YogiSession::handle_publish_message_request(const QByteArray& request)
{
    return use_terminal(request, [&](TerminalInfo& info, QDataStream&) -> QByteArray {
        const void*  data = request.data() + 5;
        const size_t size = request.size() - 5;

        switch (info.terminal->type()) {
        case yogi::terminal_type::PUBLISH_SUBSCRIBE:
            static_cast<yogi::RawPublishSubscribeTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::CACHED_PUBLISH_SUBSCRIBE:
            static_cast<yogi::RawCachedPublishSubscribeTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::PRODUCER:
            static_cast<yogi::RawProducerTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::CACHED_PRODUCER:
            static_cast<yogi::RawCachedProducerTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::MASTER:
            static_cast<yogi::RawMasterTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::CACHED_MASTER:
            static_cast<yogi::RawCachedMasterTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::SLAVE:
            static_cast<yogi::RawSlaveTerminal&>(*info.terminal).publish(data, size);
            break;

        case yogi::terminal_type::CACHED_SLAVE:
            static_cast<yogi::RawCachedSlaveTerminal&>(*info.terminal).publish(data, size);
            break;

        default:
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        return make_response();
    });
}

QByteArray YogiSession::handle_monitor_received_publish_messages_request(const QByteArray& request)
{
    return use_terminal(request, [&](TerminalInfo& info, QDataStream&) -> QByteArray {
        const void*  data = request.data() + 5;
        const size_t size = request.size() - 5;

        bool hasCache = false;
        yogi::Optional<std::vector<char>> cachedMessage;

        switch (info.terminal->type()) {
        case yogi::terminal_type::PUBLISH_SUBSCRIBE:
            create_message_observer_and_add_callback<yogi::RawPublishSubscribeTerminal>(info, &YogiSession::on_published_message_received);
            break;

        case yogi::terminal_type::CACHED_PUBLISH_SUBSCRIBE:
            create_message_observer_and_add_callback<yogi::RawCachedPublishSubscribeTerminal>(info, &YogiSession::on_cached_published_message_received);
            hasCache = true;
            cachedMessage = get_cached_message<yogi::RawCachedPublishSubscribeTerminal>(info);
            break;

        case yogi::terminal_type::CONSUMER:
            create_message_observer_and_add_callback<yogi::RawConsumerTerminal>(info, &YogiSession::on_published_message_received);
            break;

        case yogi::terminal_type::CACHED_CONSUMER:
            create_message_observer_and_add_callback<yogi::RawCachedConsumerTerminal>(info, &YogiSession::on_cached_published_message_received);
            hasCache = true;
            cachedMessage = get_cached_message<yogi::RawCachedConsumerTerminal>(info);
            break;

        case yogi::terminal_type::MASTER:
            create_message_observer_and_add_callback<yogi::RawMasterTerminal>(info, &YogiSession::on_published_message_received);
            break;

        case yogi::terminal_type::CACHED_MASTER:
            create_message_observer_and_add_callback<yogi::RawCachedMasterTerminal>(info, &YogiSession::on_cached_published_message_received);
            hasCache = true;
            cachedMessage = get_cached_message<yogi::RawCachedMasterTerminal>(info);
            break;

        case yogi::terminal_type::SLAVE:
            create_message_observer_and_add_callback<yogi::RawSlaveTerminal>(info, &YogiSession::on_published_message_received);
            break;

        case yogi::terminal_type::CACHED_SLAVE:
            create_message_observer_and_add_callback<yogi::RawCachedSlaveTerminal>(info, &YogiSession::on_cached_published_message_received);
            hasCache = true;
            cachedMessage = get_cached_message<yogi::RawCachedSlaveTerminal>(info);
            break;

        default:
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        auto response = make_response();
        if (hasCache) {
            response += helpers::to_byte_array(cachedMessage.has_value());
            if (cachedMessage.has_value()) {
                response.append(cachedMessage->data(), static_cast<int>(cachedMessage->size()));
            }
        }

        return response;
    });
}

QByteArray YogiSession::handle_scatter_gather_request(const QByteArray& request)
{
    return use_terminal(request, [&](TerminalInfo& info, QDataStream&) {
        yogi::raw_operation_id opId;

        switch (info.terminal->type()) {
        case yogi::terminal_type::SCATTER_GATHER: {{
            auto op = static_cast<yogi::RawScatterGatherTerminal&>(*info.terminal)
                .async_scatter_gather(request.data() + 5, static_cast<std::size_t>(request.size() - 5),
                    [&](auto& res, auto&& msg) {
                        return this->on_gathered_message_received(info, res, std::move(msg));
                    }
                );

            opId = op.operation_id();
            info.sgOperations.emplace(std::make_pair(opId, std::move(op)));
            }}
            break;

        case yogi::terminal_type::CLIENT: {{
            auto op = static_cast<yogi::RawClientTerminal&>(*info.terminal)
                .async_request(request.data() + 5, static_cast<std::size_t>(request.size() - 5),
                    [&](auto& res, auto&& msg) {
                        return this->on_response_received(info, res, std::move(msg));
                    }
                );

            opId = op.operation_id();
            info.scOperations.emplace(std::make_pair(opId, std::move(op)));
            }}
            break;

        default:
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        return make_response() + helpers::to_byte_array(opId);
    });
}

QByteArray YogiSession::handle_monitor_received_scatter_messages_request(const QByteArray& request)
{
    return use_terminal(request, [&](TerminalInfo& info, QDataStream&) {
        switch (info.terminal->type()) {
        case yogi::terminal_type::SCATTER_GATHER:
            create_message_observer_and_add_callback<yogi::RawScatterGatherTerminal>(info, &YogiSession::on_scattered_message_received);
            break;

        case yogi::terminal_type::SERVICE:
            create_message_observer_and_add_callback<yogi::RawServiceTerminal>(info, &YogiSession::on_request_received);
            break;

        default:
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }

        return make_response();
    });
}

QByteArray YogiSession::handle_respond_to_scattered_message_request(const QByteArray& request)
{
    return use_terminal(request, [&](TerminalInfo& info, QDataStream& stream) {
        auto opId = helpers::read_from_stream<yogi::raw_operation_id>(&stream);

        switch (info.terminal->type()) {
        case yogi::terminal_type::SCATTER_GATHER:
            return respond_to_scattered_message(info.sgScatteredMessages, opId, request);

        case yogi::terminal_type::SERVICE:
            return respond_to_scattered_message(info.scRequests, opId, request);

        default:
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }
    });
}

QByteArray YogiSession::handle_ignore_scattered_message_request(const QByteArray& request)
{
    return use_terminal(request, [&](TerminalInfo& info, QDataStream& stream) {
        auto opId = helpers::read_from_stream<yogi::raw_operation_id>(&stream);

        switch (info.terminal->type()) {
        case yogi::terminal_type::SCATTER_GATHER:
            return ignore_scattered_message(info.sgScatteredMessages, opId);

        case yogi::terminal_type::SERVICE:
            return ignore_scattered_message(info.scRequests, opId);

        default:
            return make_response(RES_INVALID_TERMINAL_TYPE);
        }
    });
}

QByteArray YogiSession::handle_start_custom_command_request(const QByteArray& request)
{
    if (request.size() < 2 || request[request.size() - 1] != '\0') {
        return make_response(RES_INVALID_REQUEST);
    }

    auto parts = request.mid(1, request.length() - 2).split('\0');
    QString cmd = parts[0];
    QStringList args;
    for (int i = 1; i < parts.size(); ++i) {
        args.push_back(parts[i]);
    }

    auto command = CustomCommandService::instance().start_command(cmd, args);

    if (!command) {
        return make_response(RES_INVALID_REQUEST);
    }

    QMutexLocker lock(&m_commandLutMutex);
    auto id = ++m_lastCommandId;
    m_commandLut.insert(id, std::move(command));

    return make_response() + helpers::to_byte_array(id);
}

QByteArray YogiSession::handle_terminate_custom_command_request(const QByteArray& request)
{
    QByteArray req_(request);
    QDataStream stream(&req_, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto cmdId = helpers::read_from_stream<unsigned>(&stream);

    QMutexLocker lock(&m_commandLutMutex);
    bool erased = m_commandLut.remove(cmdId) > 0;
    return make_response(erased ? RES_OK : RES_INVALID_COMMAND_ID);
}

QByteArray YogiSession::handle_write_custom_command_stdin(const QByteArray& request)
{
    QByteArray req_(request);
    QDataStream stream(&req_, QIODevice::ReadOnly);
    stream.skipRawData(1);

    auto cmdId = helpers::read_from_stream<unsigned>(&stream);

    QMutexLocker lock(&m_commandLutMutex);
    auto it = m_commandLut.find(cmdId);
    if (it == m_commandLut.end()) {
        return make_response(RES_INVALID_COMMAND_ID);
    }

    (*it)->write_stdin(request.mid(5));

    return make_response();
}

void YogiSession::on_binding_state_changed(BindingInfo& info, yogi::binding_state state)
{
    QByteArray data;
    data += helpers::to_byte_array(info.id);
    data += helpers::to_byte_array(state);
    emit(notify_client(m_socket, make_response(MON_BINDING_STATE_CHANGED) + data));
}

void YogiSession::on_builtin_binding_state_changed(TerminalInfo& info, yogi::binding_state state)
{
    QByteArray data;
    data += helpers::to_byte_array(info.id);
    data += helpers::to_byte_array(state);
    emit(notify_client(m_socket, make_response(MON_BUILTIN_BINDING_STATE_CHANGED) + data));
}

void YogiSession::on_subscription_state_changed(TerminalInfo& info, yogi::subscription_state state)
{
    QByteArray data;
    data += helpers::to_byte_array(info.id);
    data += helpers::to_byte_array(state);
    emit(notify_client(m_socket, make_response(MON_SUBSCRIPTION_STATE_CHANGED) + data));
}

void YogiSession::on_published_message_received(TerminalInfo& info, const std::vector<char>& payload, yogi::cached_flag cached)
{
    QByteArray data;
    data += helpers::to_byte_array(info.id);
    data.append(payload.data(), static_cast<int>(payload.size()));
    emit(notify_client(m_socket, make_response(MON_PUBLISHED_MESSAGE_RECEIVED) + data));
}

void YogiSession::on_cached_published_message_received(TerminalInfo& info, const std::vector<char>& payload, yogi::cached_flag cached)
{
    QByteArray data;
    data += helpers::to_byte_array(info.id);
    data += helpers::to_byte_array(cached);
    data.append(payload.data(), static_cast<int>(payload.size()));
    emit(notify_client(m_socket, make_response(MON_CACHED_PUBLISHED_MESSAGE_RECEIVED) + data));
}

void YogiSession::on_scattered_message_received(TerminalInfo& info, yogi::RawScatterGatherTerminal::ScatteredMessage&& msg)
{
    auto msg_ = std::make_shared<yogi::RawScatterGatherTerminal::ScatteredMessage>(std::move(msg));
    emit(received_sg_scatter_message(&info, msg_));
}

yogi::control_flow YogiSession::on_gathered_message_received(TerminalInfo& info, const yogi::Result& result, yogi::RawScatterGatherTerminal::GatheredMessage&& msg)
{
    if (!result) {
        return yogi::control_flow::STOP;
    }

    auto msg_ = std::make_shared<yogi::RawScatterGatherTerminal::GatheredMessage>(std::move(msg));
    emit(received_sg_gather_message(&info, msg_));

    return yogi::control_flow::CONTINUE;
}

void YogiSession::on_request_received(TerminalInfo& info, yogi::RawServiceTerminal::Request&& request)
{
    auto request_ = std::make_shared<yogi::RawServiceTerminal::Request>(std::move(request));
    emit(received_sc_request(&info, request_));
}

yogi::control_flow YogiSession::on_response_received(TerminalInfo& info, const yogi::Result& result, yogi::RawClientTerminal::Response&& response)
{
    if (!result) {
        return yogi::control_flow::STOP;
    }

    auto response_ = std::make_shared<yogi::RawClientTerminal::Response>(std::move(response));
    emit(received_sc_response(&info, response_));

    return yogi::control_flow::CONTINUE;
}

void YogiSession::on_dns_lookup_finished(QHostInfo info)
{
	QByteArray json;
	json += "{";

	json += "\"error\":";
	if (info.error() == QHostInfo::NoError) {
		json += "null";
	}
	else {
		json += "\"" + info.errorString() + "\"";
	}

	json += ",";

	json += "\"addresses\":[";
	if (!info.addresses().empty()) {
		for (auto& address : info.addresses()) {
			json += "\"" + address.toString() + "\",";
		}

		json.chop(1);
	}
	json += "]";

	json += ",";

	json += "\"hostname\":\"" + info.hostName() + "\"";

	json += "}";

	auto data = helpers::to_byte_array(info.lookupId()) + json;
	emit(notify_client(m_socket, make_response(ASY_DNS_LOOKUP) + data));
}

void YogiSession::on_process_update(CustomCommandService::Command* command, QProcess::ProcessState state, QByteArray out, QByteArray err, int exitCode, QProcess::ProcessError error)
{
    QMutexLocker lock(&m_commandLutMutex);

    auto cmdIt = m_commandLut.begin();
    while (cmdIt != m_commandLut.end()) {
        if (cmdIt->get() == command) {
            break;
        }

        ++cmdIt;
    }

    if (cmdIt == m_commandLut.end()) {
        return;
    }

    QByteArray data;
    data += helpers::to_byte_array(cmdIt.key());
    data += helpers::to_byte_array(state == QProcess::ProcessState::Running);
    data += helpers::to_byte_array(exitCode);
    data += helpers::to_byte_array(out.size());
    data += out;
    data += helpers::to_byte_array(err.size());
    data += err;

    switch (error) {
    case QProcess::ProcessError::FailedToStart: data += helpers::to_byte_array("Failed to start"s); break;
    case QProcess::ProcessError::Crashed:       data += helpers::to_byte_array("Crashed"s);         break;
    case QProcess::ProcessError::Timedout:      data += helpers::to_byte_array("Timed out"s);       break;
    case QProcess::ProcessError::ReadError:     data += helpers::to_byte_array("Read error"s);      break;
    case QProcess::ProcessError::WriteError:    data += helpers::to_byte_array("Write error"s);     break;
    default:                                    data += helpers::to_byte_array(""s);                break;
    }

    emit(notify_client(m_socket, make_response(ASY_CUSTOM_COMMAND_STATE) + data));
}

void YogiSession::handle_received_sg_scatter_message(TerminalInfo* info, std::shared_ptr<yogi::RawScatterGatherTerminal::ScatteredMessage> msg)
{
    QByteArray data;
    data += helpers::to_byte_array(info->id);
    data += helpers::to_byte_array(msg->operation_id());
    data.append(msg->data().data(), static_cast<int>(msg->data().size()));

    {{
        QMutexLocker lock(&m_terminalLutMutex);
        info->sgScatteredMessages.emplace(std::make_pair(msg->operation_id(), std::move(*msg)));
    }}

    emit(notify_client(m_socket, make_response(MON_SCATTERED_MESSAGE_RECEIVED) + data));
}

void YogiSession::handle_received_sg_gather_message(TerminalInfo* info, std::shared_ptr<yogi::RawScatterGatherTerminal::GatheredMessage> msg)
{
    QByteArray data;
    data += helpers::to_byte_array(info->id);
    data += helpers::to_byte_array(msg->operation_id());
    data += helpers::to_byte_array(msg->flags());
    data.append(msg->data().data(), static_cast<int>(msg->data().size()));

    if (msg->flags() & yogi::gather_flags::FINISHED) {
        QMutexLocker lock(&m_terminalLutMutex);
        info->sgOperations.erase(msg->operation_id());
    }

    emit(notify_client(m_socket, make_response(MON_GATHERED_MESSAGE_RECEIVED) + data));
}

void YogiSession::handle_received_sc_request(TerminalInfo* info, std::shared_ptr<yogi::RawServiceTerminal::Request> request)
{
    QByteArray data;
    data += helpers::to_byte_array(info->id);
    data += helpers::to_byte_array(request->operation_id());
    data.append(request->data().data(), static_cast<int>(request->data().size()));

    {{
        QMutexLocker lock(&m_terminalLutMutex);
        info->scRequests.emplace(std::make_pair(request->operation_id(), std::move(*request)));
    }}

    emit(notify_client(m_socket, make_response(MON_SCATTERED_MESSAGE_RECEIVED) + data));
}

void YogiSession::handle_received_sc_response(TerminalInfo* info, std::shared_ptr<yogi::RawClientTerminal::Response> response)
{
    QByteArray data;
    data += helpers::to_byte_array(info->id);
    data += helpers::to_byte_array(response->operation_id());
    data += helpers::to_byte_array(response->flags());
    data.append(response->data().data(), static_cast<int>(response->data().size()));

    if (response->flags() & yogi::gather_flags::FINISHED) {
        QMutexLocker lock(&m_terminalLutMutex);
        info->scOperations.erase(response->operation_id());
    }

    emit(notify_client(m_socket, make_response(MON_GATHERED_MESSAGE_RECEIVED) + data));
}

YogiSession::YogiSession(QWebSocket* socket, yogi::Node& node, const QString& clientIdentification, QObject* parent)
: QObject(parent)
, m_logger("Yogi Session")
, m_logPrefix(clientIdentification + ':')
, m_clientIdentification(clientIdentification)
, m_socket(socket)
, m_node(node)
, m_leaf(yogi::ProcessInterface::scheduler())
, m_connection(m_node, m_leaf)
, m_monitoringConnections(false)
, m_monitoringKnownTerminals(false)
, m_lastTerminalId(0)
, m_lastBindingId(0)
, m_lastCommandId(0)
, m_commandLutMutex(QMutex::RecursionMode::Recursive)
{
    YOGI_LOG_INFO(m_logger, "YOGI session for " << m_clientIdentification << " started");

    qRegisterMetaType<std::shared_ptr<yogi::RawScatterGatherTerminal::ScatteredMessage>>("std::shared_ptr<yogi::RawScatterGatherTerminal::ScatteredMessage>");
    qRegisterMetaType<std::shared_ptr<yogi::RawScatterGatherTerminal::GatheredMessage>>("std::shared_ptr<yogi::RawScatterGatherTerminal::GatheredMessage>");
    qRegisterMetaType<std::shared_ptr<yogi::RawServiceTerminal::Request>>("std::shared_ptr<yogi::RawServiceTerminal::Request>");
    qRegisterMetaType<std::shared_ptr<yogi::RawClientTerminal::Response>>("std::shared_ptr<yogi::RawClientTerminal::Response>");

    m_qtConnections.append(connect(&CustomCommandService::instance(), &CustomCommandService::process_update, this, &YogiSession::on_process_update));
    m_qtConnections.append(connect(this, &YogiSession::received_sg_scatter_message, this, &YogiSession::handle_received_sg_scatter_message));
    m_qtConnections.append(connect(this, &YogiSession::received_sg_gather_message,  this, &YogiSession::handle_received_sg_gather_message));
    m_qtConnections.append(connect(this, &YogiSession::received_sc_request,         this, &YogiSession::handle_received_sc_request));
    m_qtConnections.append(connect(this, &YogiSession::received_sc_response,        this, &YogiSession::handle_received_sc_response));
}

YogiSession::~YogiSession()
{
    for (auto connection : m_qtConnections) {
        disconnect(connection);
    }

    YOGI_LOG_INFO(m_logger, "YOGI session for " << m_clientIdentification << " destroyed");
}

QByteArray YogiSession::handle_request(const QByteArray& request)
{
    try {
        if (!request.isEmpty()) {
            switch (request[0]) {
            case REQ_VERSION:
                return handle_version_request(request);

            case REQ_CURRENT_TIME:
                return handle_current_time_request(request);

            case REQ_TEST_COMMAND:
                return handle_test_command(request);

            case REQ_KNOWN_TERMINALS:
                return handle_known_terminals_request(request);

            case REQ_KNOWN_TERMINALS_SUBTREE:
                return handle_known_terminals_subtree_request(request);

		    case REQ_FIND_KNOWN_TERMINALS:
			    return handle_find_known_terminals(request);

            case REQ_MONITOR_KNOWN_TERMINALS:
                return handle_monitor_known_terminals_request(request);

            case REQ_CONNECTION_FACTORIES:
                return handle_connection_factories_request(request);

            case REQ_CONNECTIONS:
                return handle_connections_request(request);

            case REQ_MONITOR_CONNECTIONS:
                return handle_monitor_connections_request(request);

            case REQ_CLIENT_ADDRESS:
                return handle_client_address_request(request);

		    case REQ_START_DNS_LOOKUP:
			    return handle_dns_lookup_request(request);

            case REQ_CREATE_TERMINAL:
                return handle_create_terminal_request(request);

            case REQ_DESTROY_TERMINAL:
                return handle_destroy_terminal_request(request);

            case REQ_CREATE_BINDING:
                return handle_create_binding_request(request);

            case REQ_DESTROY_BINDING:
                return handle_destroy_binding_request(request);

            case REQ_MONITOR_BINDING_STATE:
                return handle_monitor_binding_state_request(request);

		    case REQ_MONITOR_BUILTIN_BINDING_STATE:
			    return handle_monitor_builtin_binding_state_request(request);

            case REQ_MONITOR_SUBSCRIPTION_STATE:
                return handle_monitor_subscription_state_request(request);

            case REQ_PUBLISH_MESSAGE:
                return handle_publish_message_request(request);

            case REQ_MONITOR_RECEIVED_PUBLISH_MESSAGES:
                return handle_monitor_received_publish_messages_request(request);

            case REQ_SCATTER_GATHER:
                return handle_scatter_gather_request(request);

            case REQ_MONITOR_RECEIVED_SCATTER_MESSAGES:
                return handle_monitor_received_scatter_messages_request(request);

            case REQ_RESPOND_TO_SCATTERED_MESSAGE:
                return handle_respond_to_scattered_message_request(request);

            case REQ_IGNORE_SCATTERED_MESSAGE:
                return handle_ignore_scattered_message_request(request);

            case REQ_START_CUSTOM_COMMAND:
                return handle_start_custom_command_request(request);

            case REQ_TERMINATE_CUSTOM_COMMAND:
                return handle_terminate_custom_command_request(request);

            case REQ_WRITE_CUSTOM_COMMAND_STDIN:
                return handle_write_custom_command_stdin(request);
            }
        }
    }
    catch (const yogi::Failure& failure) {
        YOGI_LOG_ERROR(m_logger, "Handling request " << request.toHex().data() << " failed: " << failure);
        return make_response(RES_API_ERROR) + failure.what();
    }
    catch (const std::exception& e) {
        YOGI_LOG_ERROR(m_logger, "Handling request " << request.toHex().data() << " failed: " << e.what());
        return make_response(RES_INTERNAL_SERVER_ERROR);
    }

    YOGI_LOG_ERROR(m_logger, "Invalid request: " << request.toHex().data());
    return make_response(RES_INVALID_REQUEST);
}
