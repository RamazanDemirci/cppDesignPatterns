#include "Kid.h"

void Kid::TellMeAboutName()
{
	printf("My name is %s\n", name.c_str());
}

void Kid::TellMeAboutAge()
{
	printf("I am %d years old\n", age);
}

void Kid::TellMeAboutFavorFood()
{
	printf("My favor food is %s\n", favorFood.c_str());
}

std::string Kid::getName() { return name; }

void Kid::setName(std::string name) { this->name = name; }

int Kid::getAge() { return age; }

void Kid::setAge(int age) { this->age = age; }

std::string Kid::getFavorFood() { return favorFood; }

void Kid::setFavorFood(std::string favorFood) { this->favorFood = favorFood; }
