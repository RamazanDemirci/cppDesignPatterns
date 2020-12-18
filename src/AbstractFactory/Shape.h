#pragma once

class Shape
{
public:
    Shape();
    virtual void draw() = 0;

protected:
    int id;
    static int total;
};
