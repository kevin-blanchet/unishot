#include "GameObject.h"

#include "SceneManager.h"
#include "Math.h"
#include "LogManager.h"

GameObject::GameObject()
{
	this->setId(0);
	this->setType("GameObject");
	this->setPosition(0, 0);
	this->setSpeed(0);
	this->setDisplayLayer(MAX_DISPLAY_LAYER / 2);

	SM.insertGameObject(this);
}

GameObject::~GameObject()
{
	SM.removeGameObject(this);
}

void GameObject::update()
{
}

void GameObject::fixedUpdate()
{
}

void GameObject::draw()
{
}

void GameObject::setId(int newId)
{
	this->id = newId;
}

int GameObject::getId() const
{
	return this->id;
}

void GameObject::setType(std::string newType)
{
	this->type = newType;
}

std::string GameObject::getType() const
{
	return this->type;
}

void GameObject::setPosition(sf::Vector2f newPosition)
{
	this->position = newPosition;
}

void GameObject::setPosition(float newX, float newY)
{
	this->position.x = newX;
	this->position.y = newY;
}

sf::Vector2f GameObject::getPosition() const
{
	return this->position;
}

int GameObject::getDisplayLayer() const
{
	return this->displayLayer;
}

int GameObject::setDisplayLayer(int newLayer)
{
	if (newLayer > MAX_DISPLAY_LAYER || newLayer < 0) return false;
	this->displayLayer = newLayer;
	return true;
}

void GameObject::setVelocity(sf::Vector2f newVelocity)
{
	this->direction = Math::V2::Normalize(newVelocity);
	this->speed = Math::V2::Length(newVelocity);
}

sf::Vector2f GameObject::getVelocity()
{
	return Math::V2::Multiply(this->direction , this->speed);
}

void GameObject::setDirection(sf::Vector2f newDirection)
{
	this->direction = newDirection;
}

sf::Vector2f GameObject::getDirection() const
{
	return this->direction;
}

void GameObject::setSpeed(float newSpeed)
{
	this->speed = newSpeed;
}

float GameObject::getSpeed() const
{
	return this->speed;
}

bool GameObject::eventHandler(const Event* event)
{
	//return true if handled
	return false;
}