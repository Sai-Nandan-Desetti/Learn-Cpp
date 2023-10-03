#include "point3d.h"
#include <iostream>

Point3d::Point3d() = default;

Point3d::Point3d(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3d::setValues(int x, int y, int z)
{
    *this = Point3d(x, y, z);
}

void Point3d::print()
{
    std::cout << '<' << this->x << ", " << this->y << ", " << this->z << '>';
}

bool Point3d::isEqual(const Point3d& that)
{
    return this->x == that.x and this->y == that.y and this->z == that.z;
}
