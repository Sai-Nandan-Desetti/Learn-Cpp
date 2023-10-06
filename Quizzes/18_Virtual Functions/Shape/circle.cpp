#include "circle.h"

int Circle::getRadius() const
{
    return m_radius;
}

std::ostream &Circle::print(std::ostream &out) const
{
    return out << "Circle(" << m_center << ", radius " << m_radius << ")"; 
}
