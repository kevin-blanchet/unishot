#include "CollisionEvent.h"

CollisionEvent::CollisionEvent()
{
	setType(Event::EventType::CollisionEvent);
}

CollisionEvent::CollisionEvent(GameObject* p_go1, GameObject* p_go2, sf::Vector2f pos)
	: p_firstObject(p_go1)
	, p_secondObject(p_go2)
	, m_position(pos)
{
	setType(Event::EventType::CollisionEvent);
}

GameObject* CollisionEvent::GetFirstObject() const
{
	return p_firstObject;
}

void CollisionEvent::SetFirstObject(GameObject* p_go)
{
	p_firstObject = p_go;
}

GameObject* CollisionEvent::GetSecondObject()
{
	return p_secondObject;
}

void CollisionEvent::SetSecondObject(GameObject* p_go)
{
	p_secondObject = p_go;
}

sf::Vector2f CollisionEvent::GetPosition()
{
	return m_position;
}

void CollisionEvent::SetPosition(sf::Vector2f position)
{
	m_position = position;
}
