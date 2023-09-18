#ifndef GRADES_H
#define GRADES_H

#include <string_view>
#include <vector>


struct StudentGrade
{
    std::string_view m_name{};
    char m_grade{};
};


class GradeMap
{
private:    
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](std::string_view name);
};

#endif
