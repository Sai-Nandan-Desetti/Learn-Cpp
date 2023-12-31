#include "point3d.h"
#include <iostream>

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2{1, 2, 3};    

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3{3, 4, 5};    ;

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}
