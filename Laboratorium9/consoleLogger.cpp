#include "consoleLogger.h"
namespace loggers{
    void ConsoleLogger::log(std::string text){
        std::cout << getCurrentTimeInTextForm() << text <<std::endl;
    }
    Logger& ConsoleLogger::instance(){
        static ConsoleLogger singleton;
        return singleton;
    }
}