#pragma once

#include <SFML/System/Vector2.hpp>

namespace Math {

namespace V2 {

sf::Vector2f Up();
sf::Vector2f Down();
sf::Vector2f Left();
sf::Vector2f Right();
sf::Vector2f One();
sf::Vector2f Zero();

sf::Vector2f Normalize(sf::Vector2f v);
float Length(sf::Vector2f v);

sf::Vector2f Add(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f Substract(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f Scale(sf::Vector2f v1, sf::Vector2f v2);
float Distance(sf::Vector2f v1, sf::Vector2f v2);
float Dot(sf::Vector2f v1, sf::Vector2f v2);

sf::Vector2f Multiply(sf::Vector2f v, float f);
sf::Vector2f Divide(sf::Vector2f v, float f);

bool Equals(sf::Vector2f v1, sf::Vector2f v2);

float VectToDeg(sf::Vector2f v);
float VectToRad(sf::Vector2f v);

}

}