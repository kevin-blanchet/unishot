#define _CRT_SECURE_NO_WARNINGS
#include "LogManager.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdarg>

LogManager& LogManager::getInstance()
{
    static LogManager* logManager = new LogManager();
    return *logManager;
}

void LogManager::consoleLog(const char* fmt, ...)
{
    char oString[255];

    va_list args;
    va_start(args, fmt);

    vsprintf(oString, fmt, args);

    va_end(args);

    std::cout << getTimeString() << " - " << oString << std::endl;
}

void LogManager::errorLog(const char* fmt, ...)
{
    char oString[255];

    va_list args;
    va_start(args, fmt);

    vsprintf(oString, fmt, args);

    va_end(args);

    std::cerr << getTimeString() << " - " << oString << std::endl;
}

std::string LogManager::getTimeString()
{
    std::stringstream ss;

    time_t now;
    time(&now);
    struct tm* p_time = localtime(&now);

    ss << std::setw(2) << std::setfill('0') << p_time->tm_hour
        << ":" << std::setw(2) << std::setfill('0') << p_time->tm_min
        << ":" << std::setw(2) << std::setfill('0') << p_time->tm_sec;

    return ss.str();
}

LogManager::LogManager()
{
    this->setType("LogManager");
}