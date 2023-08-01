#ifndef IO_H
#define IO_H

#include "monsters.h"
#include <iostream>
#include <limits>

std::istream& operator>>(std::istream& in, MonsterType& monsterType);
std::ostream& operator<<(std::ostream& out, const MonsterType& monsterType);

inline void ignoreLine()
{    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void inputCleanup()
{
    if (!std::cin)
    {
        if (std::cin.eof())
            exit(0);

        std::cin.clear();
        ignoreLine();
    }
    else
        ignoreLine();
}

#endif
