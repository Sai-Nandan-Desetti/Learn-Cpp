#ifndef MONSTERS_H
#define MONSTERS_H

#include <string_view>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime
};

struct Monster
{
    MonsterType type {};
    std::string_view name {};
    int health {};
};

std::string_view getValue(const MonsterType&);
void printMonster(const Monster&);

#endif
