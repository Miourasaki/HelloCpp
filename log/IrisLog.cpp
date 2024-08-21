//
// Created by root on 2024/8/21.
//
#include <iostream>
#include <ctime>

#include "IrisLog.h"

namespace IrisLog {

    Logger::Logger() = default;
    void Logger::setLevel(LogLevel logLevel) {
        this->m_logLevel = logLevel;
    }

    void Logger::info(char *message) const {

        if (this->m_logLevel >= LogLevel::Info) {
            std::time_t now = std::time(nullptr);
            std::cout << std::ctime(&now) << "[INFO]" << message << std::endl;
        }
    }



} // IrisLog