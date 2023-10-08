#include "fraction.h"

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.m_nr << '/' << f.m_dr << '\n';
}
