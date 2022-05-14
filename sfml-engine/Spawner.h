#pragma once
#include "GameObject.h"
#include "Enemies.h"

#include "DisplayManager.h"

class Spawner : 
    public GameObject
{
public:
    Spawner();
    virtual ~Spawner();
    void spawnEnemy(int n);

private: 
};

//void Game::spawnAsteroids(int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        float coord = static_cast<float>(rand() % (this->window->getSize().x + this->window->getSize().y));
//        if (coord > this->window->getSize().x) {
//            this->asteroids.push_back(Asteroid(0, coord - this->window->getSize().x));
//        }
//        else {
//            this->asteroids.push_back(Asteroid(coord, 0));
//        }
//    }
//}