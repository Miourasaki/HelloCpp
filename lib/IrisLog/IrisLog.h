//
// Created by Miourasaki on 2024/8/21.
//

#ifndef IRISLOG_H
#define IRISLOG_H
#include <fstream>

namespace IrisLog
{

    enum LogLevel
    {
        OFF,
        FATAL,
        ERROR,
        WARN,
        INFO,
        DEBUG,
        TRACE,
        ALL,
    };

    enum LogOutputTime
    {
        DataTime,
        Time
    };

    class Logger
    {
    private:
        int m_logLevel = LogLevel::ERROR;
        int m_logOutputTime = LogOutputTime::DataTime;
        bool m_logOutColorful = true;

        bool m_logOutputToFile = false;
        std::ofstream m_logOutputFile;
    public:
        Logger();
        Logger(LogLevel logLevel, LogOutputTime logOutputTime, bool logOutColorful, bool logOutputToFile);
        ~Logger();
    public:
        void optionUseArgv(int argc, char *argv[]);
        void setLevel(LogLevel logLevel);
        void setOutputTime(LogOutputTime logOutputTime);
        void setOutColorful(bool logOutColorful);
        void openOutputFile();
        void closeOutputFile();
    private:
        void log(const char *message, LogLevel logLevel);
    public:
        void fatal(const char *message);
        void error(const char *message);
        void warn(const char *message);
        void info(const char *message);
        void debug(const char *message);
        void trace(const char *message);
    };

} // IrisLog

#endif //IRISLOG_H
