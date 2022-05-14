#pragma once
#include "GameObject.h"
#include <array>
#include "DisplayManager.h"

class Enemies :
    public GameObject
{
public:
    Enemies();
    virtual ~Enemies();

    //bool eventHandler(const Event* event);

    virtual void draw();
    virtual void update();

    sf::Texture enemy;
    sf::Sprite sprite_enemy;
    enum Dir {
        Down
        , Left
        , Right
        , Up
    };

    std::array<int, 4> walkAnimFrames;
    std::array<int, 4> runAnimFrames;
    bool walking;
    //bool isMovingUp = false;
    //bool isMovingDown = false;
    //bool isMovingRight = false;
    //bool isMovingLeft = false;
    int currentAnimIndex;
    Dir animDirection;
    float deltaAnim;

    //sf::Vector2i anim;
    //bool reset = false;

private:
    int getCurrentAnimationIndex();
    int getCurrentAnimationSize();
    Enemies::Dir getCurrentDirection();
};
