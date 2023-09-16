#include "io.h"


std::istream& operator>>(std::istream& in, MonsterType& monsterType)
{
    int input {};
    in >> input;

    monsterType = static_cast<MonsterType>(input - 1);
    /* 
    The options in the menu (in main.cpp) start from 1.
    But the constants in MonsterType start from 0.
    That's why we need to do `input - 1`.
    */
    return in;
}


std::ostream& operator<<(std::ostream& out, const MonsterType& monsterType)
{
    return out << getValue(monsterType);
}
