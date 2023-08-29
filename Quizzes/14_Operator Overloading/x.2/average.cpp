#include "average.h"

Average& Average::operator+=(const Average& other)
{
    m_total += other.m_total;
    m_count += other.m_count;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
    return out << static_cast<double>(avg.m_total) / avg.m_count;
}
