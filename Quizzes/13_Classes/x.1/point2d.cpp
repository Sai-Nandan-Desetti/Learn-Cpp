#include "point2d.h"
#include <cmath>
#include <iostream>

void Point2d::print()
{
    std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}

double Point2d::distanceTo(const Point2d& other)
{
    return std::sqrt(std::pow(this->m_x - other.m_x, 2) + std::pow(this->m_y - other.m_y, 2));
}
