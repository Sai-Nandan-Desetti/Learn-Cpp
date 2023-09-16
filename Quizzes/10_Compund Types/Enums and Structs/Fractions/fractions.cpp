#include "fractions.h"
#include "io.h"
#include <iostream>
#include <string_view>


Fraction getFraction()
{
    Fraction f {};

    std::cout << "Enter a value for the numerator: ";    
    std::cin >> f.numerator;    
    do
    {
        std::cout << "Enter a value for the denominator: ";        
        std::cin >> f.denominator;
        inputCleanup();

    } while (f.denominator == 0);

    std::cout << '\n';
    return f;
}


Fraction multiply(Fraction x, Fraction y)
{
    return { x.numerator * y.numerator, x.denominator * y.denominator };
}


void print(const Fraction& f)
{
    std::cout << f.numerator << "/" << f.denominator;
}
