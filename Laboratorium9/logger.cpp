#include "logger.h"
namespace loggers{
    std::string getCurrentTimeInTextForm()
    {
        time_t now = time(nullptr);
        char buffer[100] = {};
        strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S ", gmtime(&now));
        return std::string(buffer);
    }
}