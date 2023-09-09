#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "teacher.h"
#include <vector>
#include <functional>

class Department
{
private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
    void add(const Teacher&);

    friend std::ostream& operator<<(std::ostream&, const Department&);
};

#endif
