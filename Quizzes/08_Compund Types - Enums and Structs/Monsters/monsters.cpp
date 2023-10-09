#include "monsters.h"
#include "io.h"
#include <iostream>


std::string_view getValue(const MonsterType &monsterType)
{
    using enum MonsterType;

    switch (monsterType)
    {
    case ogre:
        return "Ogre";
    case dragon:
        return "Dragon";
    case orc:
        return "Orc";
    case giant_spider:
        return "Giant Spider";
    case slime:
        return "Slime";
    default:
        return "";
    }
}


void printMonster(const Monster &monster)
{
    std::cout << "This " << monster.type << " is named " << monster.name << " and has " << monster.health << " health.\n";
}
