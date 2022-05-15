#pragma once
#include "Event.h"

#include "GameObject.h"

class CollisionEvent :
    public Event
{
public:
    CollisionEvent();
    CollisionEvent(GameObject* p_go1, GameObject* p_go2, sf::Vector2f pos);

    GameObject* GetFirstObject() const;
    void SetFirstObject(GameObject* p_go);
    GameObject* GetSecondObject();
    void SetSecondObject(GameObject* p_go);
    sf::Vector2f GetPosition();
    void SetPosition(sf::Vector2f position);

private:
    GameObject* p_firstObject;
    GameObject* p_secondObject;
    sf::Vector2f m_position;
};

