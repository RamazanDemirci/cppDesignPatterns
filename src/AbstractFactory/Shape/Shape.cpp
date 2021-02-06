#include "Shape.h"

int Shape::total = 0;

Shape::Shape()
{
    id = total++;
}