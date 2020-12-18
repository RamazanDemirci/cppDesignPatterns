#pragma once

#include "Factory.h"

class RobustShapeFactory : public Factory
{
public:
    Shape *createCurvedInstance();
    Shape *createStraightInstance();
};