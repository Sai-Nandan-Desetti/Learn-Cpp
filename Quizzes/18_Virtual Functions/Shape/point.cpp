#include "point.h"

std::ostream& operator<<(std::ostream& out, const Point& point)
{
    return out << "Point(" << point.m_x << ", " << point.m_y << ")";
}
