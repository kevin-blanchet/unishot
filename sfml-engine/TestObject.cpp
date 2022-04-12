#include "TestObject.h"

#include "LogManager.h"

TestObject::TestObject()
{
    testCircle = sf::CircleShape(100.f);
    testCircle.setFillColor(sf::Color::Green);
}

TestObject::~TestObject()
{
}

bool TestObject::eventHandler(const Event* event)
{
    return false;
}

void TestObject::draw()
{
    DM.getWindow()->draw(testCircle);
}
