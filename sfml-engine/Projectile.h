#pragma once

#include "GameObject.h"

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/CircleShape.hpp"

const float PROJECTILE_DEFAULT_SIZE = 5.f;
const sf::Color PROJECTILE_DEFAULT_COLOR = sf::Color::Red;

class Projectile: public GameObject
{
public:
	Projectile(sf::Vector2f position, sf::Vector2f velocity);

    virtual void draw();
    virtual void update();
private:
	sf::CircleShape testCircle;
};

