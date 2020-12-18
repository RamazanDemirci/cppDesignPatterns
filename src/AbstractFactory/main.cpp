#include "Factory.h"
#include "Circle.h"
#include "Square.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "SimpleShapeFactory.h"
#include "RobustShapeFactory.h"

#define SIMPLE

int main()
{
#ifdef SIMPLE
    Factory *factory = new SimpleShapeFactory;
#elif ROBUST
    Factory *factory = new RobustShapeFactoryCls;
#endif
    Shape *shapes[3];

    shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
    shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
    shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->draw();
    }

    return 0;
}
