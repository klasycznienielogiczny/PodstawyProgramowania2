#ifndef LABORATORIUM9_DATABASELOGGER_H
#define LABORATORIUM9_DATABASELOGGER_H
#include "logger.h"
namespace loggers{
    class DatabaseLogger:public Logger{
    public:
        void log(std::string text) override;
        static Logger& instance();
    private:
        DatabaseLogger() = default;
        ~DatabaseLogger() = default;
    };
}
#endif //LABORATORIUM9_DATABASELOGGER_H
