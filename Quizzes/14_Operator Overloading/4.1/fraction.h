#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

    void reduce();
    
public:
    Fraction(int nr = 0, int dr = 1) : m_numerator{ nr }, m_denominator{ dr }
    {        
        reduce();
    }        

    friend Fraction operator*(const Fraction& f, const Fraction& g);    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);
};

#endif
