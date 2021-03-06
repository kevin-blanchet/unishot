#pragma once

#include <string>

class Event
{
public:
	enum class EventType {
		Undefined = 0
		, KeyboardEvent
		, MouseEvent
		, CollisionEvent
	};

	Event();
	virtual ~Event();

	void setType(EventType newEventType);
	EventType getType() const;
private:
	EventType eventType;
};

