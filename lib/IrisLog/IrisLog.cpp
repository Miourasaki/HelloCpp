//
// Created by root on 2024/8/21.
//
#include <iostream>
#include <ctime>
#include <filesystem>
#include <fstream>

#include "IrisLog.h"

using namespace IrisLog;

std::string strfTime(const char *format)
{

    time_t timeStamp;
    time(&timeStamp);
    char tmp[64];
    strftime(tmp, sizeof(tmp), format, localtime(&timeStamp));
    return tmp;
}

std::string getFormatTime(int logOutputTime)
{
    switch (logOutputTime)
    {
        default:
        case LogOutputTime::DataTime:
            return strfTime("%Y-%m-%d %H:%M:%S");
            break;
        case LogOutputTime::Time:
            return strfTime("%H:%M:%S");
            break;
    }
}

namespace IrisLog
{
//    Init IrisLog logger code
    Logger::Logger() = default;

    Logger::Logger(LogLevel logLevel, LogOutputTime logOutputTime, bool logOutColorful, bool logOutputToFile)
    {
        this->m_logLevel = logLevel;
        this->m_logOutputTime = logOutputTime;
        this->m_logOutColorful = logOutColorful;
        if (logOutputToFile) openOutputFile();
    };

    Logger::~Logger()
    {
        if (this->m_logOutputFile)
        {
            m_logOutputFile.close();
            std::filesystem::path filePath = "logs/latest.log";
            if (std::filesystem::exists(filePath))
            {
                std::filesystem::path resultPath = "logs/" + strfTime("%Y-%m-%d_%H-%M-%S") + ".log";
                std::filesystem::rename(filePath, resultPath);
            }
        }

    }


//    IrisLog logger options code
    void Logger::setLevel(LogLevel logLevel)
    {
        this->m_logLevel = logLevel;
    }

    void Logger::setOutputTime(LogOutputTime logOutputTime)
    {
        this->m_logOutputTime = logOutputTime;
    }

    void Logger::setOutColorful(bool logOutColorful)
    {
        this->m_logOutColorful = logOutColorful;
    }

    void Logger::openOutputFile()
    {
        std::filesystem::path filePath = "logs/latest.log";

        this->m_logOutputFile.open(filePath, std::ios::app);

        if (!this->m_logOutputFile)
        {
            this->error("Can't open ./logs directory, please create \"logs\" directory in the running directory.");
            return;
        }
        this->m_logOutputToFile = true;

    }

    void Logger::closeOutputFile()
    {
        this->m_logOutputToFile = false;
    }

//    Implement code
    void Logger::log(const char *message, LogLevel logLevel)
    {
        if (this->m_logLevel >= logLevel)
        {
            std::string prefix;
            std::string color;
            std::string textColor = "";
            switch (logLevel)
            {
                default:
                case INFO:
                    prefix = "INFO";
                    color = "2";
                    break;
                case FATAL:
                    prefix = "FATAL";
                    color = "0";
                    textColor = "\033[30m";
                    break;
                case ERROR:
                    prefix = "ERROR";
                    color = "1";
                    textColor = "\033[31m";
                    break;
                case WARN:
                    prefix = "WARN";
                    color = "3";
                    textColor = "\033[33m";
                    break;
                case DEBUG:
                    prefix = "DEBUG";
                    color = "4";
                    textColor = "\033[37m";
                    break;
                case TRACE:
                    prefix = "TRACE";
                    color = "5";
            }

            std::string finalFormatTime = getFormatTime(this->m_logOutputTime);
            std::string finalPrefix = " \033[1;36;4" + color + "m " + prefix + " \033[0m ";
            std::string finalMessage = textColor + message + "\033[0m";

            std::string final = finalFormatTime + " [" + prefix + "] " + message;
            std::string finalColorful = finalFormatTime + finalPrefix + finalMessage;

            if (this->m_logOutColorful)
                std::cout << finalColorful << std::endl;
            else
                std::cout << final << std::endl;

            if (this->m_logOutputFile && this->m_logOutputFile)
                this->m_logOutputFile << final << std::endl;
        }
    }


//    Interface code
    void Logger::fatal(const char *message) { log(message, LogLevel::FATAL); }

    void Logger::error(const char *message) { log(message, LogLevel::ERROR); }

    void Logger::warn(const char *message) { log(message, LogLevel::WARN); }

    void Logger::info(const char *message) { log(message, LogLevel::INFO); }

    void Logger::debug(const char *message) { log(message, LogLevel::DEBUG); }

    void Logger::trace(const char *message) { log(message, LogLevel::TRACE); }

} // IrisLog