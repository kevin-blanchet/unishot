#pragma once
#include <array>

#include "GameObject.h"

#include "DisplayManager.h"
#include "Rifle.h"

#include <SFML/Graphics/CircleShape.hpp>

class TestObject :
    public GameObject
{
public:
    TestObject();
    virtual ~TestObject();

    bool eventHandler(const Event* event);

    virtual void draw();
    virtual void update();

    void fire();

    sf::Vector2f m_pos;
    
    sf::Texture player;
    sf::Sprite sprite_player;
    enum Dir {
        Down
        , Left
        , Right
        , Up
    };

    std::array<int, 4> walkAnimFrames;
    std::array<int, 4> runAnimFrames;
    bool walking;
    bool isMovingUp = false;
    bool isMovingDown = false;
    bool isMovingRight = false;
    bool isMovingLeft = false;
    int currentAnimIndex;
    Dir animDirection;
    float deltaAnim;

private:
    int getCurrentAnimationIndex();
    int getCurrentAnimationSize();
    TestObject::Dir getCurrentDirection();
    Rifle go_r;
};