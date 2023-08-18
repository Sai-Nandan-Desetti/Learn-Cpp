/**
 * @file monsterType.h
 * @author DSN
 * @brief Defines various types of monsters
 * @version 0.1
 * @date 2023-08-18
 * 
 */

#ifndef MONSTERTYPE_H
#define MONSTERTYPE_H

#include <string_view>
#include <iostream>

/**
 * @brief The type of a monster
 * @details
 *  - Default initialization is used for the monsters.
 *  - So, \c max_monster_types can be used to get the number of types of monsters we have.
 * 
 */
enum class MonsterType
{
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,

    max_monster_types
};

// use the monster types without the `MonsterType::` prefix
using enum MonsterType;


/**
 * @brief Get the type of a monster as a string
 * 
 * @param type 
 * @return std::string_view 
 */
std::string_view getName(const MonsterType& type);

/**
 * @brief Overloads \c << to print a \c MonsterType as a string
 * 
 * @param out 
 * @param type 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const MonsterType& type);


#endif
