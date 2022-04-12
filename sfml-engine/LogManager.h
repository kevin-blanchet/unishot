#pragma once

#include "Manager.h"

#include <string>

#define LM LogManager::getInstance()

class LogManager :
    public Manager
{
public:
    static LogManager& getInstance();

    void consoleLog(const char* fmt, ...);
    /* TODO : output error log to file */
    void errorLog(const char* fmt, ...);
    std::string  getTimeString();
private:
    LogManager(); //Singleton - Le constructeur est privé
    LogManager(const LogManager&) = delete; //Singleton - pas de copie
    LogManager& operator=(const LogManager&) = delete; //Singleton - pas d'assignation
};

