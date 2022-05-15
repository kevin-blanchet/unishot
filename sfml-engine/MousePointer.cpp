#include "MousePointer.h"

#include "DisplayManager.h"
#include "MouseEvent.h"
#include "Math.h"

MousePointer::MousePointer()
{
    setPosition(-Math::V2::One());

    pointer = sf::CircleShape(2.f);
    pointer.setFillColor(sf::Color::Black);
}

bool MousePointer::eventHandler(const Event* event)
{
    switch (event->getType())
    {
    case Event::EventType::MouseEvent:
    {
        const MouseEvent* mEvent = dynamic_cast<const MouseEvent*>(event);
        switch (mEvent->getMouseAction())
        {
        case sf::Event::EventType::MouseMoved:
            setPosition(mEvent->getMousePosition());
            break;
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
    return false;
}

void MousePointer::draw()
{
    pointer.setPosition(getPosition());

    DM.getWindow()->draw(pointer);
}

void MousePointer::update()
{
}
