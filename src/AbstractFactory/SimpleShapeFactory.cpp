#include "Circle.h"
#include "Square.h"
#include "SimpleShapeFactory.h"

Shape *SimpleShapeFactory::createCurvedInstance()
{
    return new Circle;
}
Shape *SimpleShapeFactory::createStraightInstance()
{
    return new Square;
}