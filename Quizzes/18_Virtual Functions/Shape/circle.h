#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"
#include <iostream>

class Circle : public Shape
{
private:
    Point m_center;
    int m_radius;

public:
    Circle(
        Point center,
        int radius
    ) :
    Shape(),
    m_center{ center },
    m_radius{ radius }
    {        
    }    

    int getRadius() const;
    std::ostream& print(std::ostream&) const;    

};

#endif
