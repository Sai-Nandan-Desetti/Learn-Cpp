#include "fixedpoint.h"
#include <cmath> // std::ceil

/**
 * @details
 * Ensure that the signs of both the components are the same.
 *  - If either of them is negative, both of them should be.
 */
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
 * - Assert that the fractional component is in the range (-fractionRange, fractionRange).
 * - Note:
 *  - Do not assign default values when defining the function in \c fixedpoint.cpp as well.
 * 
 */
FixedPoint2::FixedPoint2(std::int16_t integer, std::int8_t fraction)
{
    assert(fraction > -fractionRange and fraction < fractionRange);
    setValue(integer, fraction);
}

/**
 * @details Round \c num to 2 decimal places and then delineate the integral and fractional components.
 * - Example 1: To convert \c num=2.759 to a fixed-point number.
 * @code {.cpp}
 * n = num * 100; // n = 275.9
 * n = ceil(n); // n = 276
 * integer = n / 100; // integer = 2
 * fraction = n % 100; // fraction = 76
 * @endcode
 * 
 * - Example 2: To convert \c num=-2.759 to a fixed-point number
 * @code {.cpp}
 * n = num * 100; // n = -275.9
 * n = ceil(n); // n = -276;
 * integer = n / 100; // integer = -2
 * fraction = n % 100; // fraction = -76
 * @endcode
 * - Note that
 *  - \c ceil rounds away from zero (i.e. the result of \c ceil(x) is further away from zero than \c x )
 *  - Output of \c % is a negative number, which turns out to be very useful here:
 *      - \c x%100 gives the last two digits for any number-- negative or positive.
 */
FixedPoint2::FixedPoint2(double num)
{    
    std::int16_t num_integer{ static_cast<std::int16_t>(std::ceil(num * fractionRange)) };

    setValue(num_integer / fractionRange, static_cast<std::int8_t>(num_integer % fractionRange));
}

/**
 * @details
 * Examples:
 * @code {.cpp}
 * FixedPoint{ 2, 32 } // 2 + 0.01 * 32
 * FixedPoint{ 2, -8 } // -2 + 0.01 * -8
 * @endcode
 * 
 */
FixedPoint2::operator double() const
{    
    return m_integer + static_cast<double>(m_fraction) / fractionRange;
}

/**
 * @details
 * By default, adding the unary \c - converts the number to an \c int. So, we need to explicitly convert them back to the designated types for the two components, respectively.
 */
FixedPoint2 operator-(const FixedPoint2& f)
{    
    return { static_cast<std::int16_t>(-f.m_integer), static_cast<std::int8_t>(-f.m_fraction) };
}

/**
 * @details
 * Since we're dealing with exact representations of the fixed-point numbers, we can simply check for the equality of both the integeral and fractional components.
 */
bool operator==(const FixedPoint2& f, const FixedPoint2& g)
{
    return f.m_integer == g.m_integer and f.m_fraction == g.m_fraction;
}

/**
 * @details
 * Convert each number to a double, add the doubles, and return a \c FixedPoint2 object constructed from the resultant double.
 */
FixedPoint2 operator+(const FixedPoint2& f, const FixedPoint2& g)
{
    return static_cast<double>(f) + static_cast<double>(g);
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num)
{
    return out << static_cast<double>(num);
}

/**
 * @details
 * 1. The data stored in \c in is inserted into a \c double
 * 2. The \c double is used to construct a \c FixedPoint2 object
 * 3. Which is assigned to the input parameter \c num.
 *  - We do not need to overload the \c operator= because the default one (provided by the compiler) works for us.
 */
std::istream& operator>>(std::istream& in, FixedPoint2& num)
{
    double input{};
    in >> input;
    num = FixedPoint2{ input };

    return in;
}
