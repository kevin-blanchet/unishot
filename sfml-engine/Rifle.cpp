#include "Rifle.h"

#include "DisplayManager.h"
#include "LogManager.h"
#include "Math.h"

Rifle::Rifle()
{
	cannon = sf::RectangleShape({ 10.f, 25.f });
	cannon.setFillColor(RIFLE_DEFAULT_COLOR);
	cannon.setOrigin({ 5.f, -25.f });
}

void Rifle::draw()
{
	cannon.setPosition(getPosition());
	cannon.setRotation(Math::V2::VectToDeg(getDirection()));

	DM.getWindow()->draw(cannon);
}

void Rifle::update()
{
}
