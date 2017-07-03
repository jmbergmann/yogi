#ifndef HTTP_SERVICES_FILESERVICE_HH
#define HTTP_SERVICES_FILESERVICE_HH

#include "Service.hh"

#include <yogi.hpp>

#include <QDateTime>
#include <QMimeDatabase>


namespace http_services {

class FileService : public Service
{
public:
    FileService(const yogi::ConfigurationChild& config);

    virtual void async_handle_request(request_type, const QString& path,
        const QMap<QString, QString>& header, const QByteArray& content, completion_handler) override;

private:
    struct FileCacheEntry {
        QDateTime  lastModified;
        QString    contentType;
        QByteArray content;
        bool       compressed;
    };

    yogi::Logger                  m_logger;
    QMap<QString, QString>        m_routes;
    bool						  m_gzipEnabled;
	QString                       m_gzipExecutable;
    QMap<QString, FileCacheEntry> m_fileCache;
    QMimeDatabase                 m_mimeDb;

    void setup_gzip();
    void check_gzip_exists();
    QString uri_to_file_path(const QString& uri);
    void respond_with_file_content(const QString& filePath, completion_handler completionHandler);
    FileCacheEntry* update_file_cache(const QString& filePath);
    bool compress_file(const QString& filePath, QByteArray* compressedContent);
};

} // namespace http_services

#endif // HTTP_SERVICES_FILESERVICE_HH
