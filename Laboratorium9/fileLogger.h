#ifndef LABORATORIUM9_FILELOGGER_H
#define LABORATORIUM9_FILELOGGER_H
#include "logger.h"
#include <fstream>
namespace loggers{
    class FileLogger:public Logger{
    private:
        std::fstream plik_log;
        FileLogger();
        FileLogger(const FileLogger &) {};
        ~FileLogger();
    public:
        FileLogger & operator<<(const std::string &log);
        void log(std::string text) override;
        static Logger& instance();
    };
}
#endif //LABORATORIUM9_FILELOGGER_H
