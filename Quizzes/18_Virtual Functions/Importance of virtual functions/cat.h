#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal
{
public:
    Cat(std::string_view name) : Animal{ name, "Meow" }
    {
    }    
};

#endif
