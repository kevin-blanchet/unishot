#include "Projectile.h"

#include "DisplayManager.h"

Projectile::Projectile(sf::Vector2f position, sf::Vector2f velocity)
{
	setPosition(position);
	setVelocity(velocity);

	testCircle = sf::CircleShape(PROJECTILE_DEFAULT_SIZE);
	testCircle.setFillColor(PROJECTILE_DEFAULT_COLOR);
}

void Projectile::draw()
{
	DM.getWindow()->draw(testCircle);
}

void Projectile::update()
{
	sf::Vector2f position = getPosition();
	setPosition(position + getVelocity());
	testCircle.setPosition(getPosition() - sf::Vector2f(5.f, 5.f));
}
