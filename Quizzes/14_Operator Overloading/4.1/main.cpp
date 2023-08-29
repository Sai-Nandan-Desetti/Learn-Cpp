#include "fraction.h"
#include <iostream>

int main()
{    
    std::cout << "Enter a fraction: ";
    Fraction f1{};
    std::cin >> f1;
    
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    std::cout << x << " * " << f1 << " = " << Fraction{ x * f1 } << '\n';

    return 0;
}
