#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent()
{
	setType(Event::EventType::KeyboardEvent);
}

void KeyboardEvent::setKey(sf::Keyboard::Key key)
{
	m_key = key;
}

void KeyboardEvent::setKeyboardAction(sf::Event::EventType keyboardAction)
{
	m_keyboardAction = keyboardAction;
}

sf::Event::EventType KeyboardEvent::getKeyboardAction() const
{
	return m_keyboardAction;
}

sf::Keyboard::Key KeyboardEvent::getKey() const
{
	return m_key;
}
