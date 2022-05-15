#include "SceneManager.h"
#include "GameManager.h"

SceneManager::~SceneManager()
{
    deleteAllGameObjectsInList(aliveList);
}

SceneManager& SceneManager::getInstance()
{
    static SceneManager* sceneManager = new SceneManager();
    return *sceneManager;
}

void SceneManager::insertGameObject(GameObject* go)
{
    this->aliveList.insert(this->aliveList.end(), go);
}

void SceneManager::removeGameObject(GameObject* go)
{
    for (auto it = this->aliveList.end(); it != this->aliveList.end();)
    {
        if (*it == go) {
            it = this->aliveList.erase(it);
        }
        else {
            ++it;
        }
    }
}

GameObjectList SceneManager::getAllObjects() const
{
    return this->aliveList;
}

GameObjectList SceneManager::getObjectOfType(std::string type) const
{
    GameObjectList returnVector;
    for (auto& i : this->aliveList)
    {
        if (i->getType() == type) {
            returnVector.insert(returnVector.end(), i);
        }
    }
    return returnVector;
}

GameObjectList SceneManager::getCollisions(GameObject* p_go, sf::Vector2f pos) const
{
    GameObjectList collisions;

    for (auto& i : aliveList)
    {
        if (i != p_go) {
            //todo: check for collisions
        }
    }

    return GameObjectList();
}

void SceneManager::update()
{
    float updateTime = GM.getDelta();

    for (auto& i : this->aliveList)
    {
        i->update();
    }
    this->deleteAllGameObjectsInList(deleteList);

    while (updateTime >= GM.getFixedDelta() )
    {

        for (auto& i : this->aliveList)
        {
            i->fixedUpdate();
        }
        this->deleteAllGameObjectsInList(deleteList);
        updateTime -= GM.getFixedDelta();
    }

    for (int i = 0; i <= MAX_DISPLAY_LAYER; ++i) {
        for (auto& it : this->aliveList)
        {
            if (it->getDisplayLayer() == i) it->draw();
        }
    }
}

bool SceneManager::markForDelete(GameObject* go)
{
    for (auto& i : this->deleteList)
    {
        if (i == go) {
            return 1; // l'objet est déjà dans la liste
        }
    }
    this->deleteList.insert(this->deleteList.end(), go);
    return true;
}

SceneManager::SceneManager()
{
    this->setType("SceneManager");
}

void SceneManager::deleteAllGameObjectsInList(GameObjectList list)
{
    for (size_t i = list.size(); i > 0; --i)
    {
        delete list[i];
    }
    list.clear();
}