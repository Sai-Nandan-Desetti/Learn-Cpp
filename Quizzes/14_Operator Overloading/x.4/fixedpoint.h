/**
 * @file fixedpoint.h
 * @author DSN
 * @brief Defines the \c FixedPoint2 class
 * @version 0.1
 * @date 2023-08-30
 * 
 */
#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <cstdint>
#include <iostream>
#include <cassert>

/**
 * @brief The range of the fractional component of the fixed-point number is given by \c (-fractionRange,fractionRange)
 * @details
 * - For a 2-decimal fixed-point number, it's 10sup{2};
 *  - For an n-decimal fixed-point number, it's 10sup{n}.
 * - If tomorrow, you decide that you need a 3-decimal fixed-point numbers instead of 2, just change \c fractionRange here (to 10sup{3}). 
 * 
 */
constexpr std::int8_t fractionRange{ 100 };

/**
 * @brief Implements a 2-decimal fixed-point number.
 * @details
 * - An n-decimal fixed-point number fixes the number of decimal places to n.
 *  - This is in contrast to a floating-point number that allows for variable number of decimal places.
 * - How would you implement it? What would be the attributes? How would you construct a \c FixedPoint2 object?
 *  - An obvious choice would be to have a \c double as an attribute, take a floating-point number as an argument to the constructor, and round it two decimal places.
 *  - But a catch here is that for a floating-point 5.01, for example, you do not know if it's actually 5.01 or a rounded-off version of 5.0099999.
 *  - With fixed-point numbers, we want exact representations-- no loss of precision.
 * - Have two attributes for the integral and fractional components, respectively.
 *  - The fractional component can only take values in the range (-100, 100).
 * 
 * A few examples:
 * @code {.cpp}
 * FixedPoint2{ 5, 12 } // 5.12
 * FixedPoint2{ -2, 1 } // -2.01
 * FixedPoint2{ 99, -99 } // -99.99
 * FixedPoint2{ 100, 0 } // 100
 * FixedPoint2{ -1, -2 } // -1.02
 * @endcode
 * 
 * - When we extend this to also allow construction from a \c double argument, there will be a loss of precision in converting a floating-point to a fixed-point number.
 *  - Rounding off is inevitable.
 * @code {.cpp}
 * FixedPoint2{ 3.39 }
 * FixedPoint2{ 4.999999 }
 * FixedPoint2{ -7.00111 }
 * @endcode
 * 
 * - We let the integral component be of type \c std::int16_t, and the fractional component be of type \c std::int8_t
 */
class FixedPoint2
{
private:
    std::int16_t m_integer{};
    std::int8_t m_fraction{};

    /**
     * @brief a helper function to set the integral and fractional components; used by the constructors.
     * 
     * @param integer
     * @param fraction
     */
    void setValue(std::int16_t integer, std::int8_t fraction);

public:
    /**
     * @brief Constructor for a FixedPoint2 number
     * 
     * @param integer: integral component of the number 
     * @param fraction: fractional component of the number 
     */
    FixedPoint2(std::int16_t integer = 0, std::int8_t fraction = 0);
    /**
     * @brief Constructor for a FixedPoint2 number
     * 
     * @param num: a floating-point number 
     */
    FixedPoint2(double num);

    /**
     * @brief Overloads the typecast-to-double operator
     * 
     * @return double 
     */
    operator double() const;

    /**
     * @brief Overloads the unary operator
     * 
     * @return FixedPoint2: negation of the given fixed-point number 
     */
    friend FixedPoint2 operator-(const FixedPoint2&);

    /**
     * @brief Overloads the equality operator
     * 
     * @return true: if the two numbers are equal 
     * @return false: else, they are not 
     */
    friend bool operator==(const FixedPoint2&, const FixedPoint2&);

    /**
     * @brief Overloads the binary plus operator
     * 
     * @return FixedPoint2: the sum of the two given fixed-point numbers. 
     */
    friend FixedPoint2 operator+(const FixedPoint2&, const FixedPoint2&);
};

/**
 * @brief Overloads the extraction operator.
 * 
 * @param out: A reference to the object that extracts; typically, \c std::cout 
 * @param num: A constant reference to the object that's extracted; here, a \c FixedPoint2 object
 * @return std::ostream&: a reference to the output stream. 
 */
std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);

/**
 * @brief Overloads the insertion operator.
 * 
 * @param in: A reference to the object that inserts; typically, \c std::cin 
 * @param num: A constant reference to the object that's inserted to; \c a \c FixedPoint2 object
 * @return std::istream&: a reference to the input stream. 
 */
std::istream& operator>>(std::istream& in, FixedPoint2& num);

#endif
