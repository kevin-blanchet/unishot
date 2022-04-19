#include "TestObject.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"
#include "Math.h"

#include "LogManager.h"

TestObject::TestObject()
{
    testCircle = sf::CircleShape(100.f);
    testCircle.setFillColor(sf::Color::Green);
}

TestObject::~TestObject()
{
}

bool TestObject::eventHandler(const Event* event)
{
    switch (event->getType())
    {
    case Event::EventType::KeyboardEvent:
    {
        const KeyboardEvent* kEvent = dynamic_cast<const KeyboardEvent*>(event);
        switch (kEvent->getKey())
        {
        case sf::Keyboard::Z:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                setVelocity(Math::V2::Up() + getVelocity());
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                setVelocity(getVelocity() - Math::V2::Up());
            }
            break;
        case sf::Keyboard::S:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                setVelocity(Math::V2::Down() + getVelocity());
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                setVelocity(getVelocity() - Math::V2::Down());
            }
            break;
        case sf::Keyboard::Q:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                setVelocity(Math::V2::Left() + getVelocity());
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                setVelocity(getVelocity() - Math::V2::Left());
            }
            break;
        case sf::Keyboard::D:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                setVelocity(Math::V2::Right() + getVelocity());
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                setVelocity(getVelocity() - Math::V2::Right());
            }
            break;
        default:
            break;
        }
        break;
    }
    case Event::EventType::MouseEvent:
    {
        const MouseEvent* mEvent = dynamic_cast<const MouseEvent*>(event);
        switch (mEvent->getMouseAction())
        {
        case sf::Event::EventType::MouseMoved:
            setPosition(mEvent->getMousePosition());
            break;
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
    return false;
}

void TestObject::draw()
{
    DM.getWindow()->draw(testCircle);
}

void TestObject::update()
{
    sf::Vector2f position = getPosition();
    setPosition(position + getVelocity());
    testCircle.setPosition(getPosition());
}
