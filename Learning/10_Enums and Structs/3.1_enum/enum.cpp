#include <iostream>

enum Color
{
    orange,
    yellow,
    red,
    blue,
    green
};

/* Underlying type of enum MUST be an integral type */
/*
enum Constant : double
{
    PI = 3.14,
    GRAVITY = 9.8
};
*/

std::ostream& operator<< (std::ostream& out, Color color)
{
    switch(color)
    {
        case orange:    return out << "orange";
        case yellow:    return out << "yellow";
        case red:       return out << "red";
        case blue:      return out << "blue";
        case green:     return out << "green";
        default:        return out << "???";
    }
}

int main()
{
    Color myFavoriteColor { blue };
    std::cout << "My favorite color is " << blue << ".\n";

    return 0;
}
