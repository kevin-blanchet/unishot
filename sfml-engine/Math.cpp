#include "Math.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Math {

namespace V2 {

sf::Vector2f Up()
{
    return sf::Vector2f(0, -1);
}

sf::Vector2f Down()
{
    return sf::Vector2f(0, 1);
}

sf::Vector2f Left()
{
    return sf::Vector2f(-1, 0);
}

sf::Vector2f Right()
{
    return sf::Vector2f(1, 0);
}

sf::Vector2f One()
{
    return sf::Vector2f(1, 1);
}

sf::Vector2f Zero()
{
    return sf::Vector2f(0, 0);
}

float Length(sf::Vector2f v)
{
    return sqrt(Dot(v, v));
}

sf::Vector2f Normalize(sf::Vector2f v)
{
    if(Length(v) != 0)
        return v / Length(v);
    return Zero();
}

float Distance(sf::Vector2f v1, sf::Vector2f v2)
{
    return Length(v2 - v1);
}

sf::Vector2f Add(sf::Vector2f v1, sf::Vector2f v2)
{
    return sf::Vector2f(v1.x + v2.x, v1.y + v2.y);
}

sf::Vector2f Substract(sf::Vector2f v1, sf::Vector2f v2)
{
    return sf::Vector2f(v1.x - v2.x, v1.y - v2.y);
}

sf::Vector2f Scale(sf::Vector2f v1, sf::Vector2f v2)
{
    return sf::Vector2f(v1.x * v2.x, v1.y * v2.y);
}

float Dot(sf::Vector2f v1, sf::Vector2f v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

sf::Vector2f Multiply(sf::Vector2f v, float f)
{
    return sf::Vector2f(v.x * f, v.y * f);
}

sf::Vector2f Divide(sf::Vector2f v, float f)
{
    return sf::Vector2f(v.x / f, v.y / f);
}

bool Equals(sf::Vector2f v1, sf::Vector2f v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

float VectToDeg(sf::Vector2f v)
{
    return VectToRad(v) * 180 / M_PI;
}

float VectToRad(sf::Vector2f v)
{
    if (asinf(Normalize(v).x) > 0)
    {
        return -acosf(Normalize(v).y);
    }
    return acosf(Normalize(v).y);
}

}

}