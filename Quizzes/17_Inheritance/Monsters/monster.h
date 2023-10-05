/**
 * @file monster.h
 * @author DSN
 * @brief Defines a \c Monster
 * @version 0.1
 * @date 2023-10-05
 */

#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

class Monster : public Creature
{
public:
    /**
     * @brief Types of monsters
     * @details
     * - Dragon
     * - Orc
     * - Slime     
     */
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    /**
     * @brief A helper function to get the default version of a creature based on a given monster type.
     * 
     * @return const Creature& 
     */
    static const Creature& getDefaultCreature(Type);

public:
    /**
     * @brief Construct a new Monster based on a given monster type.
     * @details The default copy constructor is used to construct \c Creature
     * 
     * @param monsterType 
     */
    Monster(Type monsterType) : Creature(getDefaultCreature(monsterType))
    {    
    }

    /**
     * @brief Randomly generate a monster
     * 
     * @return Monster 
     */
    static Monster getRandomMonster();    
};

#endif
