#include "fileLogger.h"

namespace loggers{
    FileLogger::FileLogger(){
        plik_log.open("D:\\AGH\\WEAIiIB\\2 semestr\\PP2\\Laboratorium9\\logowania.txt", std::ios::app);
    }
    FileLogger::~FileLogger(){
        plik_log.close();
    }

    FileLogger & FileLogger::operator<<(const std::string &log){
        plik_log<<log;
        return *this;
    }
    void FileLogger::log(std::string text){
        plik_log<<getCurrentTimeInTextForm()<<text<<std::endl;
    }
    Logger& FileLogger::instance(){
        static FileLogger singleton;
        return singleton;
    }
}