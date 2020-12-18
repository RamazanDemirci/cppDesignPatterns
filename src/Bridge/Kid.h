#pragma once

#include <string>
#include "Talkable.h"

class Kid : public Talkable
{
public:
	virtual void TellMeAboutName() override;
	virtual void TellMeAboutAge() override;
	virtual void TellMeAboutFavorFood() override;

	std::string getName();
	int getAge();
	std::string getFavorFood();

	void setName(std::string name);
	void setAge(int age);
	void setFavorFood(std::string favorFood);

private:
	std::string name;
	int age;
	std::string favorFood;
};
