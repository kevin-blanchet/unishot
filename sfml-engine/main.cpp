#include <SFML/Graphics.hpp>
#include "LogManager.h"
#include "GameManager.h"
#include "TestObject.h"
#include "MousePointer.h"
//#include "Rifle.h"
#include "Math.h"

int main()
{

    LM.consoleLog("Begin play");

    TestObject test;
    MousePointer mp;


    GM.update();

    LM.consoleLog("End play");

    return 0;
}