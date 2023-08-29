#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <cstdint>
#include <iostream>
#include <cassert>

constexpr std::int8_t fractionRange{ 100 };

class FixedPoint2
{
private:
    std::int16_t m_integer{};
    std::int8_t m_fraction{};

    void setValue(std::int16_t integer, std::int8_t fraction);

public:
    FixedPoint2(std::int16_t integer = 0, std::int8_t fraction = 0);
    FixedPoint2(double num);

    operator double() const;
    friend FixedPoint2 operator-(const FixedPoint2&);
    friend bool operator==(const FixedPoint2&, const FixedPoint2&);
    friend FixedPoint2 operator+(const FixedPoint2&, const FixedPoint2&);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);
std::istream& operator>>(std::istream& in, FixedPoint2& num);

#endif
