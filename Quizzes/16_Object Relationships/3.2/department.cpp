#include "department.h"

void Department::add(const Teacher& teacher)
{
    m_teachers.push_back(teacher);
}

std::ostream& operator<<(std::ostream& out, const Department& dept)
{
    for (auto teacher : dept.m_teachers)
        out << teacher << '\n';

    return out;
}
