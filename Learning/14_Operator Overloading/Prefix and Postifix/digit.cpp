#include "digit.h"


Digit& Digit::operator++()
{
    m_digit = mod((m_digit + 1), numDigits);
    return *this;
}

Digit& Digit::operator--()
{
    m_digit = mod((m_digit - 1), numDigits);
    return *this;
}

Digit Digit::operator++(int)
{
    Digit temp{ *this };
    ++(*this);
    return temp;
}

Digit Digit::operator--(int)
{
    Digit temp{ *this };
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Digit& d)
{
    return out << d.m_digit;
}

std::strong_ordering operator<=>(const Digit& d1, const Digit& d2)
{
    return d1.m_digit <=> d2.m_digit;
}
