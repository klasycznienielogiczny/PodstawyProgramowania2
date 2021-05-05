#include "databaseLogger.h"
namespace loggers{
    void DatabaseLogger::log(std::string text){
        std::cout << "Do implementacji"<<std::endl;
    }
    Logger& DatabaseLogger::instance(){
        static DatabaseLogger singleton;
        return singleton;
    }
}