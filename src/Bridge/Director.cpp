#include <stdio.h>
#include "Director.h"

void Director::startChatting()
{
	printf("Hi, can you tell me your name?\n");
	this->itsTalkable->TellMeAboutName();

	printf("Hi, can you tell me your age?\n");
	this->itsTalkable->TellMeAboutAge();
}

Talkable *Director::getItsTalkable() { return this->itsTalkable; }

void Director::setItsTalkable(Talkable *itsTalkable) { this->itsTalkable = itsTalkable; }
