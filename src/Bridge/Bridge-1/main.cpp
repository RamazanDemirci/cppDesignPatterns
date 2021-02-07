
/*
 * https://www.codeproject.com/Articles/42762/Bridge-Design-Pattern
 * */

#include "Teacher.h"
#include "Director.h"
#include "Kid.h"

int main()
{
	Teacher *teacherMegan = new Teacher();
	Director *directorLisa = new Director();

	Kid *kidElizabeth = new Kid();
	kidElizabeth->setName("Elizabeth\n");
	kidElizabeth->setAge(3);
	kidElizabeth->setFavorFood("Chicken Nuggets\n");

	Kid *kidAmmie = new Kid();
	kidAmmie->setName("Ammie\n");
	kidAmmie->setAge(4);
	kidAmmie->setFavorFood("French Fries\n");

	printf("Miss Megan starts talking to Elizabeth\n");
	teacherMegan->itsTalkable = kidElizabeth;
	teacherMegan->startChatting();

	printf("Director Lisa starts talking to Ammie\n");
	directorLisa->itsTalkable = kidAmmie;
	directorLisa->startChatting();

	printf("Miss Megan starts talking to Ammie\n");
	teacherMegan->itsTalkable = kidAmmie;
	teacherMegan->startChatting();

	printf("Director Lisa starts talking to Elizabeth\n");
	directorLisa->itsTalkable = kidElizabeth;
	directorLisa->startChatting();
}
