/**
 * @file monster.h
 * @author DSN
 * @brief Defines a \c Monster
 * @version 0.1
 * @date 2023-08-18
 * 
 */

#ifndef MONSTER_H
#define MONSTER_H

#include "monsterType.h"
#include <iostream>
#include <string>
#include <array>

/**
 * @brief A monster is defined by its type, name, roar, and hit points.
 * @details
 *  - The type of a monster is defined as the \c MonsterType enum.
 * Ideally, we should define it inside this class because \c MonsterType is specific to this class.
 * But, for now, we will keep the definitions separate.
 * 
 */
class Monster
{
private:
    MonsterType m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};    

public:
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints) 
    : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
    {        
    }

    friend std::ostream& operator<<(std::ostream& out, const Monster&);
};


/**
 * @brief Overloads \c << to print a \c Monster
 * 
 * @param out 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Monster& monster);


#endif
