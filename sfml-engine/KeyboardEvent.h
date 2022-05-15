#pragma once
#include "Event.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

class KeyboardEvent :
    public Event
{
public:
    KeyboardEvent();

    void setKey(sf::Keyboard::Key key);
    void setKeyboardAction(sf::Event::EventType keyboardAction);
    sf::Event::EventType getKeyboardAction() const;
    sf::Keyboard::Key getKey() const;
    

private:
    sf::Keyboard::Key m_key;
    sf::Event::EventType m_keyboardAction;
};

