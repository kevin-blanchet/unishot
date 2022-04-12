#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "LogManager.h"
#include "SceneManager.h"
#include "DisplayManager.h"
#include "InputManager.h"

GameManager& GameManager::getInstance()
{
    static GameManager* gameManager = new GameManager();
    return *gameManager;
}

void GameManager::update()
{
    while (this->bRunning) {
        this->delta = this->clock.resetDelta();
        IM.update();
        SM.update();
        DM.update();
    }
}

void GameManager::setRunning(bool running)
{
    this->bRunning = running;
}

bool GameManager::isRunning()
{
    return this->bRunning;
}

float GameManager::getDelta()
{
    return this->delta;
}

float GameManager::getFixedDelta()
{
    return this->fixedDelta;
}

GameManager::GameManager()
{
    this->setType("GameManager");
    this->setRunning(true);

    this->delta = this->clock.getDelta();
    this->fixedDelta = 0.03f;
}