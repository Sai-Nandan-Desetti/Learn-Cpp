/**
 * @file player.h
 * @author DSN
 * @brief Defines a \c Player
 * @version 0.1
 * @date 2023-10-05
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include <string_view>


class Player : public Creature
{
private:
    int m_level{};
    static constexpr int s_MAX_LEVEL{ 20 };

public:
    // Player() = default;

    Player(std::string_view name) : Creature(name, '@', 10, 1, 0)
    {        
    }
    
    int getLevel() const;

    /**
     * @brief Increase level and damage by 1.          
     */
    void levelUp();

    /**
     * @brief A \c Player wins if they reach level 20.
     * 
     * @return true: WINNER! 
     * @return false: LEARNER. 
     */
    bool hasWon() const;
    
    /**
     * @brief Defines the effects of drinking a \c Potion.
     * 
     */
    void drink(Potion potion);
};

#endif
