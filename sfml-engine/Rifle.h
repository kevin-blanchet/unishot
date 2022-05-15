#pragma once
#include "GameObject.h"

#include <SFML/Graphics/RectangleShape.hpp>

const sf::Color RIFLE_DEFAULT_COLOR = sf::Color::Blue;

class Rifle :
    public GameObject
{
public:
    Rifle();

    //bool eventHandler(const Event* event);

    virtual void draw();
    virtual void update();

protected:
    sf::RectangleShape cannon;
};

