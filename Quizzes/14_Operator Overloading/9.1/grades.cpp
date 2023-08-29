#include "grades.h"
#include <algorithm>


char& GradeMap::operator[](std::string_view name)
{   
    // use a lambda to define a predicate for `find_if`,
    // wherein we compare against student names
    auto found = std::find_if(m_map.begin(), m_map.end(),
    [&name](const auto& student) {
        // `name` is captured as a reference by the lambda
        return student.m_name == name;
    });

    if (found == m_map.end())
    {
        m_map.push_back({ name });
        return m_map.back().m_grade;
    }
    
    return found->m_grade;
}
