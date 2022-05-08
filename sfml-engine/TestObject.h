#pragma once
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

    sf::CircleShape testCircle;
    Rifle go_r;
};