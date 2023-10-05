#include "potion.h"

std::string_view getName(Potion potion)
{
    using enum Potion;

    switch(potion)
    {        
        case health: return "Health";
        case strength: return "Strength";
        case poison: return "Poison";
        default: return "???";
    }
}

int operator+(Potion potion)
{
    return static_cast<int>(potion);
}

std::ostream& operator<<(std::ostream& out, Potion potion)
{
    return out << getName(potion);
}
