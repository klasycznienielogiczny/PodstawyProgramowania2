#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
private:
    int xFrom;
    int yFrom;
    int xTo;
    int yTo;
public:
    Rectangle(int xF, int yF, int xT, int yT) : xFrom(xF), yFrom(yF), xTo(xT), yTo(yT) {};

    bool isIn(int x, int y) const override{
        return ((x >= this->xFrom) and (x<= this->xTo) and (y>= this->yFrom) and (y<= this->yTo));
    };

    int getX() const{
        return this->xFrom;
    };

    int getY() const{
        return this->yFrom;
    };

    int getXTo() const{
        return this->xTo;
    };

    int getYTo() const{
        return this->yTo;
    };

    ~Rectangle() = default;
};
} // namespace Shapes

#endif // RECTANGLE_H
