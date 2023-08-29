#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>
#include <string_view>

class MyString
{
private:
    std::string m_str{};

    std::string_view substr(std::size_t pos, std::size_t len);
    
public:
    MyString(std::string_view str = {}) : m_str{ str }
    {        
    }
    MyString operator()(std::size_t pos, std::size_t len);
    friend std::ostream& operator<<(std::ostream& out, const MyString&);    
};

#endif
