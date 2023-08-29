#include "point.h"

int main()
{
    Point point{}; // use default constructor to set to (0.0, 0.0, 0.0)

    if (!point)
        std::cout << "Default is set at the origin.\n";
    else
        std::cout << "Default is not set at the origin.\n";

    Point x{ 2, 3, 1 };
    std::cout << "x: " << x << '\n';

    Point y{ 1, 4, 5 };
    std::cout << "y: " << y << '\n';

    std::cout << "+x - -y: " << (+x - -y) << '\n';
    std::cout << "-x + y: " << (-x + y) << '\n';

    return 0;
}
