#include "Ellipse.h"
#include "Rectangle.h"
#include "RobustShapeFactory.h"

Shape *RobustShapeFactory::createCurvedInstance()
{
    return new Ellipse;
}
Shape *RobustShapeFactory::createStraightInstance()
{
    return new Rectangle;
}