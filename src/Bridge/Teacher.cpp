#include <string>
#include "Teacher.h"

void Teacher::startChatting()
{
	printf("What's your name?\n");
	this->itsTalkable->TellMeAboutName();

	printf("How old are you?\n");
	this->itsTalkable->TellMeAboutAge();

	printf("What's your favor food\n");
	this->itsTalkable->TellMeAboutFavorFood();
}

Talkable *Teacher::getItsTalkable() { return this->itsTalkable; }

void Teacher::setItsTalkable(Talkable *itsTalkable) { this->itsTalkable = itsTalkable; }
