#pragma once
#include "Manager.h"

#define IM InputManager::getInstance()

class InputManager :
    public Manager
{
public:
    virtual ~InputManager();

    static InputManager& getInstance();

    virtual void update();
private:
    InputManager(); //Singleton - Le constructeur est privé
    InputManager(const InputManager&) = delete; //Singleton - pas de copie
    InputManager& operator=(const InputManager&) = delete; //Singleton - pas d'assignation
};

