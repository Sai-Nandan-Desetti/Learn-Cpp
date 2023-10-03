#include "fractions.h"
#include <iostream>

int main()
{
    Fraction x{};
    x.getFraction();    
    Fraction y{};
    y.getFraction();
    
    std::cout << "Your fractions multiplied together: ";
    x.multiply(y).print();

    /* The use of an explicit constructor disallows the creation of a Fraction
    via an implicit conversion with a single value. */
    // x.multiply(2).print();
    
    std::cout << std::endl;

    return 0;
}
