#ifndef APPLE_H
#define APPLE_H

#include "fruit.h"
#include <iostream>

class Apple : public Fruit
{
private:
    double m_fiber{};

public:
    Apple(
        std::string_view name,
        std::string_view color,
        double fiber
    ) :
    Fruit{ name, color },
    m_fiber{ fiber }
    {        
    }

    double getFiber() const
    {
        return m_fiber;
    }    
};

std::ostream& operator<<(
    std::ostream& out,
    const Apple& apple
);

#endif
