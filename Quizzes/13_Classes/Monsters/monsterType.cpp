/**
 * @file monsterType.cpp
 * @author DSN
 * @brief Defines utility functions to use a \c MonsterType
 * @version 0.1
 * @date 2023-08-18
 * 
 */

#include "monsterType.h"

/**
 * @details We return \c "????" in case of an invalid \c type
 * 
 */
std::string_view getName(const MonsterType& type)
{
    switch (type)
    {
    case dragon:
        return "dragon";        
    case goblin:
        return "goblin";
    case ogre:
        return "ogre";
    case orc:
        return "orc";
    case skeleton:
        return "skeleton";
    case troll:
        return "troll";
    case vampire:
        return "vampire";
    case zombie:
        return "zombie";
    default:
        return "????";
    }
}


std::ostream& operator<<(std::ostream& out, const MonsterType& type)
{
    return out << getName(type);
}
