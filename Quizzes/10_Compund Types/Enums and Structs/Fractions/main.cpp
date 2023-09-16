#include "fractions.h"
#include <iostream>

int main()
{
    Fraction x { getFraction() };    
    Fraction y { getFraction() };

    Fraction result { multiply(x, y) };
    
    std::cout << "Your fractions multiplied together: ";
    print(result);
    std::cout << '\n';

    return 0;
}
