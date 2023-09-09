#ifndef APPLE_H
#define APPLE_H

#include "fruit.h"
#include <iostream>

class Apple : public Fruit
{
protected:
    Apple(
        std::string_view name,
        std::string_view color
    ) :
    Fruit{ name, color }
    {        
    }
    
public:
    Apple(std::string_view color) : Fruit{ "apple", color }
    {        
    }        
};

std::ostream& operator<<(
    std::ostream& out,
    const Apple& apple
);

#endif
