#ifndef AVERAGE_H
#define AVERAGE_H

#include <cstdint>
#include <iostream>

class Average
{
private:
    std::int32_t m_total{};
    std::int8_t m_count{};

public:
    Average() = default;    
    Average(std::int32_t total) : m_total{ total }, m_count{ 1 }
    {        
    }
    Average& operator+=(const Average&);
    friend std::ostream& operator<<(std::ostream& out, const Average&);
};

#endif
