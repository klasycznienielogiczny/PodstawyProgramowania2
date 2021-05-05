#include "logger.h"
namespace loggers{
    std::string getCurrentTimeInTextForm()
    {
        auto now = std::chrono::system_clock::now();
        char buffer[100] = {};
        std::time_t now_tt = std::chrono::system_clock::to_time_t(now);
        strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S ", gmtime(&now_tt));
        return std::string(buffer);
    }
}