#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>

#include "Event.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void update();
	virtual void fixedUpdate();
	virtual void draw();

	void setId(int newId);
	int getId() const;

	void setType(std::string newType);
	std::string getType() const;

	virtual void setPosition(sf::Vector2f newPosition);
	virtual void setPosition(float newX, float newY);
	sf::Vector2f getPosition() const;

	int getDisplayLayer() const;
	int setDisplayLayer(int newLayer);

	void setVelocity(sf::Vector2f newVelocity);
	sf::Vector2f getVelocity();

	void setDirection(sf::Vector2f newDirection);
	sf::Vector2f getDirection() const;

	void setSpeed(float newSpeed);
	float getSpeed() const;

	virtual bool eventHandler(const Event* event);
private:
	int id;
	std::string type;
	sf::Vector2f position;
	int displayLayer;

	sf::Vector2f direction;
	float speed;
};

