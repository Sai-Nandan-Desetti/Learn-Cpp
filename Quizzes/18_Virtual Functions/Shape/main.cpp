#include "triangle.h"
#include "circle.h"
#include <vector>
#include <iostream>

int getLargestRadius(std::vector<Shape*>);

int main()
{
    std::vector<Shape*> shapes{
        new Circle{{1, 2}, 7},
        new Triangle{{1, 2}, {3, 4}, {5, 6}},
        new Circle{{7, 8}, 3}
    };

    for (const auto& shape : shapes)
        std::cout << *shape << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(shapes) << '\n';

	for (auto& shape : shapes)
        delete shape;

    return 0;
}

int getLargestRadius(std::vector<Shape*> shapes)
{
    int maxRadius{ 0 };
    for (const auto& shape : shapes)
    {
        Circle* circle{ static_cast<Circle*>(shape) }; // if the downcast weren't valid, static_cast returns a null pointer

        // if the cast is valid, then shape indeed points to a Circle
        if (circle)
        {
            int radius{ circle->getRadius() };
            if (maxRadius < radius)
                maxRadius = radius;
        }
    }

    return maxRadius;
}
