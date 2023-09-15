#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal
{
public:
    Dog(std::string_view name) : Animal{ name, "Woof" }
    {
    }
};

#endif
