#pragma once

#include "Factory.h"

class SimpleShapeFactory : public Factory
{
public:
    Shape *createCurvedInstance();
    Shape *createStraightInstance();
};