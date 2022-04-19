#include "MouseEvent.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

MouseEvent::MouseEvent()
{
	setType(Event::EventType::MouseEvent);
}

void MouseEvent::setMouseAction(sf::Event::EventType mouseAction)
{
	m_mouseAction = mouseAction;
}

void MouseEvent::setButton(sf::Mouse::Button button)
{
	m_button = button;
}

void MouseEvent::setMousePosition(sf::Vector2f mousePosition)
{
	m_mousePosition = mousePosition;
}

sf::Event::EventType MouseEvent::getMouseAction() const
{
	return m_mouseAction;
}

sf::Mouse::Button MouseEvent::getButton() const
{
	return m_button;
}

sf::Vector2f MouseEvent::getMousePosition() const
{
	return m_mousePosition;
}
