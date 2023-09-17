#ifndef BANANA_H
#define BANANA_H

#include "fruit.h"
#include <iostream>

class Banana : public Fruit
{
public:
    Banana(std::string_view color = "yellow") : Fruit{ "banana", color }
    {        
    }
};

std::ostream& operator<<(
    std::ostream& out,
    const Banana& banana
);

#endif
