#include "fixedpoint.h"
#include <cmath> // std::ceil


void FixedPoint2::setValue(std::int16_t integer, std::int8_t fraction)
{
    if (integer < 0 or fraction < 0)
    {
        if (integer > 0)
            m_integer = -integer;
        else
            m_integer = integer;

        if (fraction > 0)
            m_fraction = -fraction;
        else
            m_fraction = fraction;
    }
    else
    {
        m_integer = integer;
        m_fraction = fraction;
    }
}

/**
 * @details
 * Assert that the fractional component is in the range (-fractionRange, fractionRange).
 * Note:
 *  - Do not assign default values when defining the function in \c fixedpoint.cpp as well.
 * 
 */
FixedPoint2::FixedPoint2(std::int16_t integer, std::int8_t fraction)
{
    assert(fraction > -fractionRange and fraction < fractionRange);
    setValue(integer, fraction);
}

FixedPoint2::FixedPoint2(double num)
{    
    std::int16_t num_integer{ static_cast<std::int16_t>(std::ceil(num * fractionRange)) };

    setValue(num_integer / fractionRange, static_cast<std::int8_t>(num_integer % fractionRange));
}

FixedPoint2::operator double() const
{    
    return m_integer + static_cast<double>(m_fraction) / fractionRange;
}

FixedPoint2 operator-(const FixedPoint2& f)
{    
    return { static_cast<std::int16_t>(-f.m_integer), static_cast<std::int8_t>(-f.m_fraction) };
}

bool operator==(const FixedPoint2& f, const FixedPoint2& g)
{
    return f.m_integer == g.m_integer and f.m_fraction == g.m_fraction;
}

FixedPoint2 operator+(const FixedPoint2& f, const FixedPoint2& g)
{
    return static_cast<double>(f) + static_cast<double>(g);
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num)
{
    return out << static_cast<double>(num);
}

std::istream& operator>>(std::istream& in, FixedPoint2& num)
{
    double input{};
    in >> input;
    num = FixedPoint2{ input };

    return in;
}
