#include "FileWatcher.hh"

#include <boost/filesystem.hpp>
#include <sys/inotify.h>
#include <string.h>
#include <string>
#include <yogi.hpp>
using namespace std::string_literals;


FileWatcher::FileWatcher(boost::asio::io_service& ios)
: m_ios(ios)
, m_inotifySd(ios)
{
    m_inotifyFd = inotify_init();
    if (m_inotifyFd == -1) {
        throw std::runtime_error("Could not initialize inotify: "s + strerror(errno));
    }

    m_inotifySd.assign(m_inotifyFd);
    start_async_read_some();
}

FileWatcher::~FileWatcher()
{
    close(m_inotifyFd);
}

void FileWatcher::watch(const std::string& pattern, handler_fn handlerFn)
{
    auto data = std::make_shared<watch_data_t>();
    data->directory       = extract_directory(pattern);
    data->filenamePattern = extract_filename_pattern(pattern);
    data->directoryWd     = add_watch(data->directory, true);
    data->handlerFn       = handlerFn;

    YOGI_LOG_DEBUG("Watching directory " << data->directory << " (without subdirectories) for changes");

    m_watches[data->directoryWd].push_back(data);
}

std::string FileWatcher::extract_directory(const std::string& pattern)
{
    auto dir = boost::filesystem::path(pattern).parent_path().native();
    if (dir.empty()) {
        dir = ".";
    }

    return dir;
}

std::regex FileWatcher::extract_filename_pattern(const std::string& pattern)
{
    return std::regex(boost::filesystem::path(pattern).filename().native());
}

FileWatcher::event_type_t FileWatcher::maskToEventType(std::uint32_t mask)
{
    if (mask & IN_CLOSE_WRITE) {
        return FILE_MODIFIED;
    }
    else if (mask & (IN_CREATE | IN_MOVED_TO)) {
        return FILE_CREATED;
    }
    else if (mask & (IN_DELETE | IN_MOVED_FROM)) {
        return FILE_DELETED;
    }
    
    YOGI_LOG_WARNING("Unexcepted inotify mask: " << std::hex << mask << ". Assuming file was modified.");
    return FILE_MODIFIED;
}

int FileWatcher::add_watch(const std::string& path, bool isDir)
{
    auto events = IN_CLOSE_WRITE | IN_CREATE | IN_MOVED_TO | IN_DELETE | IN_MOVED_FROM;
    if (isDir) {
        events |= IN_ONLYDIR;
    }

    int wd = inotify_add_watch(m_inotifyFd, path.c_str(), events);
    if (wd == -1) {
        auto msg = "Could not watch "s + (isDir ? "directory " : "file ") + path + ": " + strerror(errno);
        throw std::runtime_error(msg);
    };

    return wd;
}

void FileWatcher::start_async_read_some()
{
    m_inotifySd.async_read_some(boost::asio::buffer(m_buffer), [=](auto& ec, auto bytesRead) {
        if (!ec) {
            m_bufferStr.append(m_buffer.begin(), m_buffer.begin() + bytesRead);
            this->on_data_read();
        }
        else if (ec != boost::asio::error::operation_aborted) {
            YOGI_LOG_ERROR("Could not read inotify events: " << ec.message());
        }
    });
}

void FileWatcher::on_data_read()
{
    while (m_bufferStr.size() >= sizeof(inotify_event)) {
        auto* event = reinterpret_cast<const inotify_event*>(m_bufferStr.data());
        if (event->mask & IN_IGNORED) {
            continue;
        }

        auto watchIt = m_watches.find(event->wd);
        if (watchIt != m_watches.end()) {
            auto eventType = maskToEventType(event->mask);
            handle_event(watchIt->second, event->wd, event->name, eventType);
        }

        m_bufferStr.erase(0, sizeof(inotify_event) + event->len);
    }

    start_async_read_some();
}

void FileWatcher::handle_event(const std::vector<watch_data_ptr>& dataVec, int wd, const std::string& path, event_type_t eventType)
{
    for (auto& data : dataVec) {
        bool logged = false;
        if (does_path_match_pattern(path, data)) {
            if (!logged) {
                switch (eventType) {
                case FILE_CREATED:
                    YOGI_LOG_DEBUG("Detected created file " << path);
                    break;

                case FILE_DELETED:
                    YOGI_LOG_DEBUG("Detected deleted file " << path);
                    break;

                case FILE_MODIFIED:
                    YOGI_LOG_DEBUG("Detected modified file " << path);
                    break;
                }

                logged = true;
            }

            data->handlerFn(path, eventType);
        }
    }
}

bool FileWatcher::does_path_match_pattern(const std::string& path, const watch_data_ptr& data)
{
    if (boost::filesystem::is_directory(path)) {
        return false;
    }
    else {
        std::smatch m;
        return std::regex_match(path, m, data->filenamePattern);
    }
}
