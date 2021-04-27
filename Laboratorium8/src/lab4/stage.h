#ifndef STAGE_H
#define STAGE_H

#include <iosfwd>

namespace Shapes
{
class Shape;
}

class Stage
{
    int width, height;

    constexpr static char emptySymbol{' '};
    constexpr static char shapeSymbol{'*'};

public:
    Stage(int width, int height) : width(width), height(height)
    {}

    void drawShape2Stream(const Shapes::Shape* shape, std::ostream& stream) const{
        for(int vertical_pixel = 0; vertical_pixel <= this->height; ++vertical_pixel){
            for(int horizontal_pixel = 0; horizontal_pixel <= this->width; ++horizontal_pixel){
                if(shape->isIn(horizontal_pixel, this->height - vertical_pixel)){
                    stream << shapeSymbol;
                }
                else{
                    stream << emptySymbol;
                }
            }
            stream << "\n";
        }
    }

    ~Stage() = default;
};

#endif // STAGE_H
