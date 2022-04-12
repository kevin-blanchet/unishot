#include "Clock.h"

Clock::Clock()
{
}

float Clock::getDelta()
{
	return this->clock.getElapsedTime().asSeconds();
}

long int Clock::uGetDelta()
{
	return this->clock.getElapsedTime().asMicroseconds();
}

float Clock::resetDelta()
{
	return this->clock.restart().asSeconds();
}

long int Clock::uResetDelta()
{
	return this->clock.restart().asMicroseconds();
}
