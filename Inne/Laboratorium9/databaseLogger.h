#ifndef LABORATORIUM9_DATABASELOGGER_H
#define LABORATORIUM9_DATABASELOGGER_H
#include "logger.h"
#include "sqlite3.h"
namespace loggers{
    class DatabaseLogger:public Logger{
    public:
        sqlite3 *db;
        void log(std::string text) override;
        static Logger& instance();
    private:
        DatabaseLogger();
        ~DatabaseLogger();
    };
}
#endif //LABORATORIUM9_DATABASELOGGER_H
