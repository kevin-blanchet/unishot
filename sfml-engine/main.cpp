#include <SFML/Graphics.hpp>
#include "LogManager.h"
#include "GameManager.h"
#include "TestObject.h"
#include "Enemies.h"
#include "Spawner.h"
#include "MousePointer.h"
//#include "Rifle.h"
#include "Math.h"

int main()
{

    LM.consoleLog("Begin play");

    TestObject test;
    Enemies ennemi;
    Spawner sp;
    sp.spawnEnemy(12);
    
    MousePointer mp;

    GM.update();

    LM.consoleLog("End play");

    return 0;
}