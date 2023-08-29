#include "fraction.h"
#include <iostream>

int main()
{    
    std::cout << "Enter a fraction: ";
    Fraction f1{};
    std::cin >> f1;
    std::cout << "f1: " << f1 << '\n';
    
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    
    Fraction f2{ x * f1 };
    std::cout << "f2: " << x << " * " << f1 << " = " << f2 << '\n';    

    Fraction f3{ f1 * x };    
    std::cout << "f3: " << f1 << " * " << x << " = " << f3 << '\n';

    std::cout << "f1 += f2 += f3: " << (f1 += f2 += f3) << '\n';
    std::cout << "f1: " << f1 << '\n';
    std::cout << "f2: " << f2 << '\n';
    std::cout << "f3: " << f3 << '\n';

    return 0;
}
