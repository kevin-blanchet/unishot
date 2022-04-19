#include "Event.h"

Event::Event()
{
	setType(Event::EventType::Undefined);
}

Event::~Event()
{
}

void Event::setType(Event::EventType newEventType)
{
	this->eventType = newEventType;
}

Event::EventType Event::getType() const
{
	return this->eventType;
}