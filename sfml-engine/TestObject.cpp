#include "TestObject.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"
#include "Math.h"

#include "LogManager.h"
#include "Projectile.h"

TestObject::TestObject()
{
    testCircle = sf::CircleShape(50.f);
    testCircle.setFillColor(sf::Color::Green);
    testCircle.setOrigin({ 50.f, 50.f });
    m_pos = sf::Vector2f(0, 0);
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
        case sf::Event::EventType::MouseButtonPressed:
            if (mEvent->getButton() == sf::Mouse::Button::Left) {
                fire();
            }
            break;
        case sf::Event::EventType::MouseMoved:
            m_pos = mEvent->getMousePosition();
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
    testCircle.setPosition(getPosition());

    DM.getWindow()->draw(testCircle);
}

void TestObject::update()
{
    sf::Vector2f position = getPosition();
    setPosition(position + getVelocity());
    go_r.setPosition(getPosition());
    go_r.setDirection(Math::V2::Normalize(m_pos - getPosition()));
}

void TestObject::fire()
{
    sf::Vector2f pDirection = Math::V2::Normalize(m_pos - getPosition());
    Projectile* p = new Projectile(getPosition(), pDirection * 50.f);
}
