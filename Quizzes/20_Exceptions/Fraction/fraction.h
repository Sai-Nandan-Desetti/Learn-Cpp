#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>
#include <iostream>

class Fraction
{
private:
    int m_nr;
    int m_dr;

public:
    Fraction(
        int numerator,
        int denominator
    ) :
    m_nr{ numerator },
    m_dr{ denominator }
    {
        if (m_dr == 0)
            throw (std::runtime_error("You can't have the denominator as zero!\n"));
    }

    friend std::ostream& operator<<(std::ostream&, const Fraction&);
};

#endif
