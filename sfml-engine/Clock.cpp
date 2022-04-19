#include "Clock.h"

Clock::Clock()
{
}

float Clock::getDelta()
{
	return this->clock.getElapsedTime().asSeconds();
}

sf::Int64 Clock::uGetDelta()
{
	return this->clock.getElapsedTime().asMicroseconds();
}

float Clock::resetDelta()
{
	return this->clock.restart().asSeconds();
}

sf::Int64 Clock::uResetDelta()
{
	return this->clock.restart().asMicroseconds();
}
