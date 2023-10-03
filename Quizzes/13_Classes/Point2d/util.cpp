#include "point2d.h"
#include <cmath>

double distanceFrom(const Point2d& p, const Point2d& q)
{
    return std::sqrt(std::pow(p.m_x - q.m_x, 2) + std::pow(p.m_y - q.m_y, 2));
}
