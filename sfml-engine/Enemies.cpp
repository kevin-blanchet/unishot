#include <iostream>
#include "Enemies.h"
#include "GameManager.h"

Enemies::Enemies()
{
    if (!enemy.loadFromFile("./Ressources/Medias/ghoul.png")) {
        std::cout << "Erreur chargement du player ghoul.png" << std::endl;
    }
    enemy.setSmooth(true);

    deltaAnim = 0.f;
    walking = true;
    currentAnimIndex = 0;
    //animDirection = Down;
    walkAnimFrames = { 0, 1, 2, 1 };
    runAnimFrames = { 3, 4, 5, 6 };

    sprite_enemy.setTexture(enemy);
    sprite_enemy.setTextureRect(sf::IntRect(getCurrentAnimationIndex() * 32, getCurrentDirection() * 32, 32, 32));

}

Enemies::~Enemies()
{
}

void Enemies::draw()
{
    DM.getWindow()->draw(sprite_enemy);

}

void Enemies::update()
{
    sf::Vector2f position = getPosition();
    setPosition(position + getVelocity());

    sprite_enemy.setPosition(getPosition());

    deltaAnim += GM.getDelta();
    // std::cout << anim.x << std::endl;

    sprite_enemy.setTextureRect(sf::IntRect(getCurrentAnimationIndex() * 32, getCurrentDirection() * 32, 32, 32));

    if (deltaAnim >= 0.2f) {
        currentAnimIndex = ++currentAnimIndex % getCurrentAnimationSize();
        deltaAnim -= 0.2f;
    }
}

int Enemies::getCurrentAnimationIndex()
{
    return walking
        ? walkAnimFrames[currentAnimIndex]
        : runAnimFrames[currentAnimIndex];
}

int Enemies::getCurrentAnimationSize()
{
    return walking
        ? walkAnimFrames.size()
        : runAnimFrames.size();
}

Enemies::Dir Enemies::getCurrentDirection()
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
    else if (getDirection().x < 0.f && getDirection().x < getDirection().y) {
        return Left;
    }
    else {
        return Down;
    }
}

