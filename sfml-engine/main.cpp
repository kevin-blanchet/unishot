#include <SFML/Graphics.hpp>
#include "LogManager.h"
#include "GameManager.h"
#include "TestObject.h"

int main()
{

    LM.consoleLog("Begin play");

    TestObject test;

    GM.update();

    LM.consoleLog("End play");

    return 0;
}