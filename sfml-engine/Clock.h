#pragma once

#include <SFML/System/Clock.hpp>

class Clock
{
public:
	Clock();

	float getDelta();
	long int uGetDelta();

	float resetDelta();
	long int uResetDelta();
private:
	sf::Clock clock;
};