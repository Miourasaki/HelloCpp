//
// Created by root on 2024/8/21.
//

#ifndef HELLOCPP_IRISLOG_H
#define HELLOCPP_IRISLOG_H

namespace IrisLog {

    enum LogLevel {
        Info,
        Warning,
        Error,
        Debug,
    };

    class Logger {
    private:
        int m_logLevel = LogLevel::Error;
    public:
        explicit Logger();
        void setLevel(LogLevel logLevel);
    public:
        void info(char* message) const;
    };

} // IrisLog

#endif //HELLOCPP_IRISLOG_H
