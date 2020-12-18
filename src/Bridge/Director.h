#pragma once

#include "Talkable.h"
#include "Communicator.h"

class Director : public Communicator
{
public:
	virtual void startChatting() override;

	Talkable *getItsTalkable();
	void setItsTalkable(Talkable *itsTalkable);
};
