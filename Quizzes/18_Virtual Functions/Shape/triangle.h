#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "point.h"

class Triangle : public Shape
{
private:
    Point m_a;
    Point m_b;
    Point m_c;

public:
    Triangle(
        Point a, 
        Point b, 
        Point c
    ) :
    Shape(),
    m_a{ a },
    m_b{ b },
    m_c{ c }
    {        
    }    

    std::ostream& print(std::ostream&) const;    
};

#endif
