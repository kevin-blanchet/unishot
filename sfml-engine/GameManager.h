#pragma once

#include "Manager.h"
#include "Clock.h"

#define GM GameManager::getInstance()

class GameManager :
    public Manager
{
public:
    static GameManager& getInstance();

    virtual void update();

    void setRunning(bool running = false);
    bool isRunning();

    float getDelta();
    float getFixedDelta();
private:
    bool bRunning;

    Clock clock;
    float delta;
    float fixedDelta;

    GameManager(); //Singleton - Le constructeur est privé
    GameManager(const GameManager&) = delete; //Singleton - pas de copie
    GameManager& operator=(const GameManager&) = delete; //Singleton - pas d'assignation
};

