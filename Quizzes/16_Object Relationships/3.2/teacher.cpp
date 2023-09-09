#include "teacher.h"

std::ostream& operator<<(std::ostream& out, const Teacher& teacher)
{
    return out << teacher.m_name;
}
