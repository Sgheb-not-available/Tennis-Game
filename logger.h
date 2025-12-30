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

void Log(LogLvl lvl, const std::string& msg);
std::string LvlToString(LogLvl lvl);