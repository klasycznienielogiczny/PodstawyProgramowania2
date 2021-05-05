#ifndef LABORATORIUM9_LOGGER_H
#define LABORATORIUM9_LOGGER_H
#include <iostream>
#include <chrono>
#include <string>
namespace loggers{
    std::string getCurrentTimeInTextForm();

    class Logger{
    public:
        virtual void log(std::string text) = 0;
        static Logger& instance();
    protected:
        Logger() = default;
        ~Logger() = default;
    };
}
#endif //LABORATORIUM9_LOGGER_H
