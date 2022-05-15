#pragma once
#include "GameObject.h"

#include <SFML/Graphics/CircleShape.hpp>

class MousePointer :
    public GameObject
{
public:
    MousePointer();

    bool eventHandler(const Event* event);

    virtual void draw();
    virtual void update();

protected:
    sf::CircleShape pointer;
};

