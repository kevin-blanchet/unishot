#pragma once

#include <string>

class Event
{
public:
	Event();
	virtual ~Event();

	void setType(std::string newEventType);
	std::string getType() const;
private:
	std::string eventType;
};

