#include "car.h"


std::strong_ordering operator<=>(const Car& c1, const Car& c2)
{
    if (c1.m_make == c2.m_make)
        return c1.m_model <=> c2.m_model;

    else
        return c1.m_make <=> c2.m_make;
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    return out << '(' << car.m_make << ", " << car.m_model << ')';
}
