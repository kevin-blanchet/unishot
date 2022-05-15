#pragma once
#include "Event.h"

#include <string>

class Manager
{
public:
	Manager();
	virtual ~Manager();

	virtual void update() =0;

	std::string getType() const;
	bool isStarted() const;

	int onEvent(const Event* pEvent) const;

protected:
	void setType(std::string newType);

private:
	std::string type;
	bool bStarted;
};

