#include <iostream>
#include "TestObject.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"
#include "Math.h"

#include "LogManager.h"
#include "Projectile.h"
#include "GameManager.h"

TestObject::TestObject()
{
    if (!player.loadFromFile("./Ressources/Medias/mc.png")){
        std::cout << "Erreur chargement du player mc.png" << std::endl;
    }
    player.setSmooth(true);

    deltaAnim = 0.f;
    walking = true;
    currentAnimIndex = 0;
    //animDirection = Down;
    walkAnimFrames = { 0, 1, 2, 1 };
    runAnimFrames = { 3, 4, 5, 6 };

    sprite_player.setTexture(player);
    sprite_player.setTextureRect(sf::IntRect(getCurrentAnimationIndex() * 64, getCurrentDirection() * 64, 64, 64));
    sprite_player.setOrigin({ 32.f, 25.f });
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
        case sf::Keyboard::LShift:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                walking = !walking;
                currentAnimIndex = 0;
            }
            break;
        case sf::Keyboard::Z:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                isMovingUp = true;
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                isMovingUp = false;
            }
            
            break;
        case sf::Keyboard::S:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                isMovingDown = true;
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                isMovingDown = false;
            }
            break;
        case sf::Keyboard::Q:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                isMovingLeft = true;
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                isMovingLeft = false;
            }
            break;
        case sf::Keyboard::D:
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyPressed) {
                isMovingRight = true;
            }
            if (kEvent->getKeyboardAction() == sf::Event::EventType::KeyReleased) {
                isMovingRight = false;
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
    sprite_player.setPosition(getPosition());

    DM.getWindow()->draw(sprite_player);
}

void TestObject::update()
{
    setVelocity(Math::V2::Zero());
    if (walking) {
        setSpeed(1.f);
    }
    else {
        setSpeed(4.f);
        
    }
    if (isMovingDown || isMovingLeft || isMovingRight || isMovingUp) {
        
        if (isMovingUp) {
            setVelocity(Math::V2::Up() * getSpeed() + getVelocity());
        }
        if (isMovingDown) {
            setVelocity(Math::V2::Down() * getSpeed() + getVelocity());
        }
        if (isMovingRight) {
            setVelocity(Math::V2::Right() * getSpeed() + getVelocity());
        }
        if (isMovingLeft) {
            setVelocity(Math::V2::Left() * getSpeed() + getVelocity());
        }
    }
    else {
        setVelocity(Math::V2::Zero());
        walking = true;
    }
    sf::Vector2f position = getPosition();
    setPosition(position + getVelocity());
    go_r.setPosition(getPosition());
    go_r.setDirection(Math::V2::Normalize(m_pos - getPosition()));

    deltaAnim += GM.getDelta();
    // std::cout << anim.x << std::endl;

    sprite_player.setTextureRect(sf::IntRect(getCurrentAnimationIndex() * 64, getCurrentDirection() * 64, 64, 64));

    if (deltaAnim >= 0.2f) {
        currentAnimIndex = ++currentAnimIndex % getCurrentAnimationSize();
        deltaAnim -= 0.2f;
    }
}

int TestObject::getCurrentAnimationIndex()
{
    return walking
        ? walkAnimFrames[currentAnimIndex]
        : runAnimFrames[currentAnimIndex];
}

int TestObject::getCurrentAnimationSize()
{
    return walking
        ? walkAnimFrames.size()
        : runAnimFrames.size();
}

TestObject::Dir TestObject::getCurrentDirection()
{
    if (getDirection().y < 0.f && getDirection().y <= getDirection().x) {
        return Up;
    }
    else if (getDirection().y > 0.f && getDirection().y >= getDirection().x) {
        return Down;
    }
    else if (getDirection().x > 0.f && getDirection().x > getDirection().y) {
        return Right;
    }
    else if (getDirection().x < 0.f && getDirection().x < getDirection().y){
        return Left;
    }
    else {
        return Down;
    }
}

void TestObject::fire()
{
    sf::Vector2f pDirection = Math::V2::Normalize(m_pos - getPosition());
    Projectile* p = new Projectile(getPosition(), pDirection * 50.f);
}