#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual std::ostream& print(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream&, const Shape&);
};

#endif
