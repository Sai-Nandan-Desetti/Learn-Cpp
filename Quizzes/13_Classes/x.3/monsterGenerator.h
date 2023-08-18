/**
 * @file monsterGenerator.h
 * @author DSN
 * @brief Defines a namespace to encapsulate details regarding the random generation of a \c Monster
 * @version 0.1
 * @date 2023-08-18
 *
 */

#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include "random.h"
#include "monster.h"

/**
 * @brief Defines a utility function \c generate() to randomly generate a \c Monster
 * 
 */
namespace MonsterGenerator
{
    /**
     * @brief Randomly generates a \c Monster
     * @details
     *  - Randomly generate a number between \c 0 and \c max_monster_types-1 (defined in \c MonsterType)
     *      - Use a Mersenne Twister random number generator (defined in \c random.h) for that.
     *  - And use that to also index into static arrays of \c s_names and \c s_roars
     *  - \c hitPoints are randomly generated from \c 1-100
     * 
     * @return Monster 
     */
    inline Monster generate()
    {
        static constexpr std::array s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Bones", "Mort", "Hans", "Zonk" };
        static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*rattle*", "*hum*", "*burp*", "*mute*" };

        std::size_t idx{ static_cast<std::size_t>(Random::get(0, static_cast<int>(max_monster_types) - 1)) };                
        
        int hitPoints{ Random::get(1, 100) };

        return Monster{ static_cast<MonsterType>(idx), s_names[idx], s_roars[idx], hitPoints };
    }
}

#endif
