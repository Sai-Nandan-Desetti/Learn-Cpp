#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>
#include <compare>

template <typename T, typename U>
auto mod(T a, U b)
{   
    return (a %= b) < 0 ? a + b : a;
}

/**
 * @brief Implements a digit.
 * @details Note that a digit can only be between [0-9]
 * 
 */
class Digit
{
private:
    int m_digit;
    static constexpr int numDigits{ 10 };

public:
    Digit(int digit = 0) : m_digit{ mod(digit, numDigits) }
    {
    }

    /* 
    Note that we have to return the object so that multiple operators can be chained,
    and we have to return it by reference so that all the changes are reflected in the operand. 
    Eg: This should be allowed: `++(--(++d))`; the change caused due to the application of each operator
    must be reflected in `d`.
    */
    Digit& operator++();
    Digit& operator--();
    
    Digit operator++(int);
    Digit operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Digit& d);
    friend std::strong_ordering operator<=>(const Digit&, const Digit&);
};

#endif
