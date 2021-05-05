#include <iostream>
#include "fileLogger.h"
#include "consoleLogger.h"
#include "databaseLogger.h"

using namespace loggers;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string message("Kontrola");
    ConsoleLogger::instance().log(message);
    ConsoleLogger::instance().log("Bledna nazwa uzytkownika!");
    FileLogger::instance().log(message);
    FileLogger::instance().log("Testowy zapis do pliku");
    //ConsoleLogger::log() // na szczescie nie dziala
    //FileLogger::log(message) // na szczescie nie dziala
    return 0;
}
