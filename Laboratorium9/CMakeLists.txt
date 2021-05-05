cmake_minimum_required(VERSION 3.19)
project(Laboratorium9)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laboratorium9 main.cpp logger.h consoleLogger.h fileLogger.h databaseLogger.h logger.cpp fileLogger.cpp
        consoleLogger.cpp databaseLogger.cpp)