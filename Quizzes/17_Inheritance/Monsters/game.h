/**
 * @file game.h
 * @author DSN
 * @brief Defines the game play
 * @version 0.1
 * @date 2023-10-05
 */

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "monster.h"

class Game
{
private:
    /**
     * @brief Determines if the player has successfully fled or not.
     * 
     * @return true 
     * @return false 
     */
    static bool canEscape();

    /**
     * @brief Checks if a potion is found or not
     * 
     * @return int: -1 if not found, else a number below \c Potion::max_potions 
     */
    static int potionFound();
    
public:
    Game() = delete;
    static void play(Player& player);
};

#endif
