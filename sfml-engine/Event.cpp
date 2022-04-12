#include "Event.h"

Event::Event()
{
	setType("undefined");
}

Event::~Event()
{
}

void Event::setType(std::string newEventType)
{
	this->eventType = newEventType;
}

std::string Event::getType() const
{
	return this->eventType;
}