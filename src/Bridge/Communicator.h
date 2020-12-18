#pragma once

class Talkable;

class Communicator
{
public:
	Talkable *itsTalkable; //build a bridge between a Communicator and a talkable object (Kid)

	virtual void startChatting() = 0; //Start chatting process
};
