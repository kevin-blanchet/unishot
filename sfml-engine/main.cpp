#include <SFML/Graphics.hpp>
#include "LogManager.h"
#include "GameManager.h"

int main()
{

    LM.consoleLog("Begin play");

    GM.update();

    LM.consoleLog("End play");

    return 0;
}