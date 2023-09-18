#include "fraction.h"
#include <numeric>


void Fraction::reduce()
{
    int _gcd{ std::gcd(m_numerator, m_denominator) };
    m_numerator /= _gcd;
    m_denominator /= _gcd;
}

Fraction operator*(const Fraction& f, const Fraction& g)
{
    return { f.m_numerator * g.m_numerator, f.m_denominator * g.m_denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.m_numerator << '/' << f.m_denominator;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    in >> f.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> f.m_denominator;

    f.reduce();
    
    return in;
}

std::strong_ordering operator<=>(const Fraction& p, const Fraction& q)
{          
    return p.m_numerator * q.m_denominator <=> q.m_numerator * p.m_denominator;
}
