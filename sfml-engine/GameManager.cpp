#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "LogManager.h"
//#include "SceneManager.h"
//#include "DisplayManager.h"
//#include "InputManager.h"

GameManager& GameManager::getInstance()
{
    static GameManager* gameManager = new GameManager();
    return *gameManager;
}

void GameManager::update()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (this->bRunning) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                bRunning = false;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();




        this->delta = this->clock.resetDelta();
        float updateTime = this->delta;
        //IM.getInput();
        //SM.update();
        //while (updateTime >= this->fixedDelta)
        //{
        //    SM.fixedUpdate();
        //    updateTime -= this->fixedDelta;
        //}
        //SM.draw();
        //DM.display();
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