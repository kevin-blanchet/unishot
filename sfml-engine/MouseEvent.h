#pragma once
#include "Event.h"
#include <SFML/Window/Event.hpp>
class MouseEvent :
    public Event
{
public:
    MouseEvent();
    void setMouseAction(sf::Event::EventType mouseAction);
    void setButton(sf::Mouse::Button button);
    void setMousePosition(sf::Vector2f mousePosition);
    sf::Event::EventType getMouseAction() const;
    sf::Mouse::Button getButton() const;
    sf::Vector2f getMousePosition() const;

private:
    sf::Event::EventType m_mouseAction;
    sf::Mouse::Button m_button;
    sf::Vector2f m_mousePosition;
};

