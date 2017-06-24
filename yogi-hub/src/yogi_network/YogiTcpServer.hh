#ifndef YOGI_NETWORK_YOGITCPSERVER_HH
#define YOGI_NETWORK_YOGITCPSERVER_HH

#include <yogi.hpp>

#include <QObject>
#include <QMap>
#include <QList>
#include <QTimer>
#include <QVector>

#include <chrono>
#include <memory>
#include <atomic>


namespace yogi_network {

class YogiTcpServer : public QObject
{
    Q_OBJECT

public:
    struct ClientInformation {
        QString                               description;
        QString                               remoteVersion;
        QString                               remoteIdentification;
        bool                                  connected;
        std::chrono::system_clock::time_point stateChangedTime;
    };

    YogiTcpServer(yogi::ConfigurationChild& config, yogi::Node& node);
    virtual ~YogiTcpServer();

    QString address() const;
    unsigned port() const;
    QList<ClientInformation> connections() const;

Q_SIGNALS:
    void connection_changed(std::shared_ptr<yogi::TcpConnection> connection, ClientInformation);
    void connection_dead(std::shared_ptr<yogi::TcpConnection> connection);

private:
    const QString                                                 m_address;
    const unsigned                                                m_port;
    const QString                                                 m_identification;
    const std::chrono::milliseconds                               m_timeout;
    yogi::Logger                                                  m_logger;
    yogi::Node&                                                   m_node;
    std::unique_ptr<yogi::TcpServer>                              m_server;
    std::atomic<int>                                              m_activeAsyncOperations;
    QTimer*                                                       m_cleanupTimer;
    QMap<std::shared_ptr<yogi::TcpConnection>, ClientInformation> m_connections;
	QVector<std::shared_ptr<yogi::TcpConnection>>                 m_connectionsToDestroy;

private:
    void start_accept();
    void on_accept(const yogi::Result& res, std::shared_ptr<yogi::TcpConnection> connection);
    void assign_connection(std::shared_ptr<yogi::TcpConnection> connection);
    void start_await_death(std::shared_ptr<yogi::TcpConnection> connection);
    void on_connection_died(const yogi::Failure& failure, std::shared_ptr<yogi::TcpConnection>);

private Q_SLOTS:
    void on_connection_changed(std::shared_ptr<yogi::TcpConnection> connection, ClientInformation info);
    void on_connection_dead(std::shared_ptr<yogi::TcpConnection> connection);
    void on_periodic_cleanup();
};

} // namespace yogi_network

#endif // YOGI_NETWORK_YOGITCPSERVER_HH
