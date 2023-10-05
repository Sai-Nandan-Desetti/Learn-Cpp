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
public:
    Game() = delete;
    static void play(Player& player);
};

#endif
