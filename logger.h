#pragma once
#include <ctime>
#include <iostream>
#include <string>

enum LogLvl {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

class Logger {
    public:
        void Log(LogLvl lvl, const std::string& msg);
    private:
        std::string LvlToString(LogLvl lvl);
};