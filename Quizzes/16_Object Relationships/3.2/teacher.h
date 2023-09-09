#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <string_view>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name) : m_name{ name }
    {
    }    
    
    friend std::ostream& operator<<(std::ostream&, const Teacher&);
};

#endif
