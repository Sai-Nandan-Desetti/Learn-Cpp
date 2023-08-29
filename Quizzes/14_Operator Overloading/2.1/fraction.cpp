#include "fraction.h"
#include <numeric>

void Fraction::reduce()
{
    int _gcd{ std::gcd(m_numerator, m_denominator) };
    m_numerator /= _gcd;
    m_denominator /= _gcd;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.m_numerator << '/' << f.m_denominator;
}

Fraction operator*(const Fraction& f, const Fraction& g)
{
    return { f.m_numerator * g.m_numerator, f.m_denominator * g.m_denominator };
}
