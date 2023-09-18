#include "myString.h"
#include <cassert>

std::string_view MyString::substr(std::size_t pos, std::size_t len)
{
    return static_cast<std::string_view>(m_str).substr(pos, len);
}

MyString MyString::operator()(std::size_t pos, std::size_t len)
{    
    assert(pos + len <= m_str.length() && "MyString::operator(int, int): Substring is out of range");

    return { substr(pos, len) };
}

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
    return out << s.m_str;
}
