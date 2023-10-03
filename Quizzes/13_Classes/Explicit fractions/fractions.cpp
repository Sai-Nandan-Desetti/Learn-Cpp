#include "fractions.h"
#include "io.h"
#include <iostream>
#include <string_view>


void Fraction::getFraction()
{    
    std::cout << "Enter a value for the numerator: ";    
    std::cin >> m_nr;
    do
    {
        std::cout << "Enter a value for the denominator: ";        
        std::cin >> m_dr;
        inputCleanup();

    } while (m_dr == 0);

    std::cout << '\n';    
}


Fraction Fraction::multiply(const Fraction& other) const
{
    // need to explicitly mention "Fraction" if we use an `explicit` constructor
    return Fraction{ m_nr * other.m_nr, m_dr * other.m_dr };
}


void Fraction::print() const
{
    std::cout << m_nr << "/" << m_dr;
}
