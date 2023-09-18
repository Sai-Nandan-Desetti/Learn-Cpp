#include "point.h"


Point Point::operator-() const
{
    return { -m_x, -m_y, -m_z };
}

bool Point::operator!() const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

Point Point::operator+() const
{
    return { m_x, m_y, m_z };
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << "(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
    
    return out;
}

Point operator+(const Point& p, const Point& q)
{
    return { p.m_x + q.m_x, p.m_y + q.m_y, p.m_z + q.m_z };
}

Point operator-(const Point& p, const Point& q)
{
    return { p.m_x - q.m_x, p.m_y - q.m_y, p.m_z - q.m_z };
}
