#ifndef LABORATORIUM9_CONSOLELOGGER_H
#define LABORATORIUM9_CONSOLELOGGER_H
#include "logger.h"
namespace loggers{
    class ConsoleLogger:public Logger{
    private:
        ConsoleLogger() = default;
        ~ConsoleLogger() = default;
    public:
        friend std::ostream& operator<<(std::ostream &os, const std::string& log){
            os << log << std::endl;
            return os;
        };
        void log(std::string text) override;
        static Logger& instance();
    };
}
#endif //LABORATORIUM9_CONSOLELOGGER_H