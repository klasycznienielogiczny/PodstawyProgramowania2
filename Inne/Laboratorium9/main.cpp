#include <iostream>
#include "fileLogger.h"
#include "consoleLogger.h"
#include "databaseLogger.h"

using namespace loggers;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string message("Kontrola. chrono");
    ConsoleLogger::instance().log(message);
    ConsoleLogger::instance().log("Bledna nazwa uzytkownika! chrono");
    FileLogger::instance().log(message);
    FileLogger::instance().log("Testowy zapis do pliku. Z chrono");
    //ConsoleLogger::log() // na szczescie nie dziala
    //FileLogger::log(message) // na szczescie nie dziala
    //DatabaseLogger::log("xdd") //nie dziala. Uff
    DatabaseLogger::instance().log(message);
    DatabaseLogger::instance().log("Udalo sie zrobic.");
    return 0;
}
