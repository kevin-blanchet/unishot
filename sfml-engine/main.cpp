#include <SFML/Graphics.hpp>
#include "LogManager.h"
#include "GameManager.h"
#include "TestObject.h"
#include "Enemies.h"
#include "Spawner.h"

int main()
{

    LM.consoleLog("Begin play");

    TestObject test;
    Enemies ennemi;
    Spawner sp;
    sp.spawnEnemy(12);
    

    GM.update();

    LM.consoleLog("End play");

    return 0;
}