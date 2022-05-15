#include "Manager.h"
#include "GameObjectList.h"
#include "SceneManager.h"

Manager::Manager()
{
    bStarted = true;
    type = "Manager";
}

Manager::~Manager()
{}

void Manager::update()
{
}

std::string Manager::getType() const
{
    return this->type;
}

bool Manager::isStarted() const
{
    return this->bStarted;
}

int Manager::onEvent(const Event* pEvent) const
{
    int count = 0;

    GameObjectList gameObjects = SM.getAllObjects();
    for (auto& i : gameObjects)
    {
        i->eventHandler(pEvent);
        ++count;
    }

    return count;
}

void Manager::setType(std::string newType)
{
    this->type = newType;
}