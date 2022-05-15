#pragma once

#include <SFML/System/Clock.hpp>

class Clock
{
public:
	Clock();

	float getDelta();
	sf::Int64 uGetDelta();

	float resetDelta();
	sf::Int64 uResetDelta();
private:
	sf::Clock clock;
};