#ifndef PAIR_H
#define PAIR_H

template <typename T, typename U>
class Pair
{
protected:    
    T m_x{};
    U m_y{};

public:
    Pair(const T& x, const U& y) : m_x{ x }, m_y{ y }
    {        
    }

    T first() const
    {
        return m_x;
    }

    U second() const
    {
        return m_y;
    }
};

#endif
