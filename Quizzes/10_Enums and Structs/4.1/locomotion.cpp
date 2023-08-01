#include "locomotion.h"

int operator+(Locomotion::Legs l)
{    
    return static_cast<int>(l);
}

int getValue(Locomotion::Legs l)
{
    return +l;
}
