#include "logger.h"

void Logger::Log(LogLvl lvl, const std::string& msg) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20]; 
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    std::string logLvlStr = LvlToString(lvl);

    std::cout<<"["<<timestamp<<"] "<<logLvlStr<<": "<<msg<<std::endl;
}

std::string Logger::LvlToString(LogLvl lvl) {
    switch(lvl) {
        case LOG_DEBUG:
            return "DEBUG";
        case LOG_INFO:
            return "INFO";
        case LOG_WARNING:
            return "WARNING";
        case LOG_ERROR:
            return "ERROR";
        default:
            return "UKNOWN";
    }
}