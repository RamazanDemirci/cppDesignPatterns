#pragma once

#include "Communicator.h"
#include "Kid.h"

class Teacher : public Communicator
{
public:
	virtual void startChatting() override;

	Talkable *getItsTalkable();
	void setItsTalkable(Talkable *itsTalkable);
};
