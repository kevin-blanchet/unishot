#pragma once
#include "Manager.h"

#include "GameObject.h"
#include "GameObjectList.h"

#define SM SceneManager::getInstance()

const int MAX_DISPLAY_LAYER = 20;

class SceneManager :
    public Manager
{
public:
    virtual ~SceneManager();
    static SceneManager& getInstance();

    void insertGameObject(GameObject* go);
    void removeGameObject(GameObject* go);
    GameObjectList getAllObjects() const;
    GameObjectList getObjectOfType(std::string type) const;
    GameObjectList getCollisions(GameObject* p_go, sf::Vector2f pos) const;

    virtual void update();

    bool markForDelete(GameObject* go);
private:
    SceneManager(); //Singleton - Le constructeur est privé
    SceneManager(const SceneManager&) = delete; //Singleton - pas de copie
    SceneManager& operator=(const SceneManager&) = delete; //Singleton - pas d'assignation

    GameObjectList aliveList;
    GameObjectList deleteList;

    void deleteAllGameObjectsInList(GameObjectList list);
};

