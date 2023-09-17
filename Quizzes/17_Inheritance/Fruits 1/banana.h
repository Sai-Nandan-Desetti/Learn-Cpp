#ifndef BANANA_H
#define BANANA_H

#include "fruit.h"
#include <iostream>

class Banana : public Fruit
{
public:
    Banana(
        std::string_view name,
        std::string_view color
    ) :
    Fruit{ name, color }
    {        
    }
};

std::ostream& operator<<(
    std::ostream& out,
    const Banana& banana
);

#endif
