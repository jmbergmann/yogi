#ifndef EXECUTION_UNIT_HH
#define EXECUTION_UNIT_HH

#include "TemplateString.hh"
#include "Command.hh"
#include "FileWatcher.hh"

#include <yogi.hpp>

#include <boost/asio/io_service.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <set>
#include <chrono>
#include <memory>


class ExecutionUnit
{
public:
    ExecutionUnit(boost::asio::io_service& ios, FileWatcher& fileWatcher, std::string name,
        const yogi::ConfigurationChild& configChild, std::string defaultsConfigChildName,
        const template_string_vector& constants);
    virtual ~ExecutionUnit();

    const std::string& name() const;
    void start();

private:
    boost::asio::io_service&      m_ios;
    FileWatcher&                  m_fileWatcher;
    std::string                   m_name;
    yogi::ConfigurationChild      m_configChild;
    yogi::ConfigurationChild      m_defaultsConfigChild;
    const template_string_vector& m_constants;
    template_string_vector        m_variables;
    bool                          m_enabled;
    TemplateString                m_logfile;
    command_ptr                   m_startupCommand;
    std::chrono::milliseconds     m_startupTimeout;
    std::chrono::milliseconds     m_restartDelay;
    template_string_vector        m_filesTriggeringRestart;

protected:
    virtual void on_startup_command_finished_successfully() =0;
    virtual void on_watched_file_changed() =0;

    boost::asio::io_service& io_service();
    const template_string_vector& variables() const;
    const TemplateString& logfile() const;
    const std::chrono::milliseconds restart_delay() const;
    FileWatcher& file_watcher();

    void set_variable(const std::string& name, const std::string& value);
    bool extract_bool(const std::string& childName);
    std::chrono::milliseconds extract_duration(const std::string& childName);
    command_ptr extract_command(const std::string& childName, std::chrono::milliseconds timeout);
    void check_command_not_empty(const std::string& cmdName);
    TemplateString extract_string(const std::string& childName);
    void run_command(const command_ptr& cmd, const template_string_vector& variables,
        std::function<void (Command::exit_status_t, const std::string&, const std::string&)> completionHandler,
        bool logFailureAsError=true);
    static void log_command_output(const std::string& out, const std::string& err, bool logAsError);
    void start_timer(boost::asio::deadline_timer& timer, std::chrono::milliseconds duration,
        std::function<void ()> successHandler);

private:
    void read_configuration();
    void create_variables();
    void extract_files_triggering_restart();
    void start_watching_files();
};

typedef std::unique_ptr<ExecutionUnit> execution_unit_ptr;
typedef std::vector<execution_unit_ptr> execution_unit_ptr_vector;

std::ostream& operator<< (std::ostream& os, const ExecutionUnit& unit);

#endif // EXECUTION_UNIT_HH
