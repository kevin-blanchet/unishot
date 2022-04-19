#pragma once
#include "GameObject.h"

#include "DisplayManager.h"

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

    sf::CircleShape testCircle;
};

