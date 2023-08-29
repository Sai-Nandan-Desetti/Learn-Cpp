#include "fraction.h"
#include <iostream>

int main()
{
    Fraction f1{ 2, 5 };
    std::cout << f1 << '\n';

    Fraction f2{ 3, 8 };
    std::cout << f2 << '\n';

    Fraction f3{ f1 * f2 };
    std::cout << f3 << '\n';

    Fraction f4{ f1 * 2 };
    std::cout << f4 << '\n';

    Fraction f5{ 2 * f2 };
    std::cout << f5 << '\n';

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    std::cout << f6 << '\n';

    return 0;
}
