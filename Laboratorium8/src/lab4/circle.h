#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

namespace Shapes
{
class Circle : public Shape
{
private:
    int xCenter;
    int yCenter;
    int radius;
public:
    Circle(int xC, int yC, int r) : xCenter(xC), yCenter(yC), radius(r) {};

    bool isIn(int x, int y) const override{
        return sqrt(pow(this->xCenter - x, 2) + (pow(this->yCenter - y, 2))) <= this->radius;
    }

    int getX() const{
        return this->xCenter;
    }

    int getY() const{
        return this->yCenter;
    }

    int getRadius() const{
        return this->radius;
    }

    ~Circle() = default;
};
} // namespace Shapes

#endif // CIRCLE_H
