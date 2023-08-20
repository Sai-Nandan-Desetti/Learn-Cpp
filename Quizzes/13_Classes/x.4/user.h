/**
 * @file user.h
 * @author DSN
 * @brief Defines the \c User
 * @version 0.2
 * @date 2023-08-19
 * 
 */

#ifndef USER_H
#define USER_H

#include "player.h"


class User : public Player
{
public:    
    User(const int playerLimit) : Player("User", playerLimit)
    {}        

    /**
     * @brief Ask the user if he wants to HIT or STAND
     * 
     */
    void chance(Deck& deck) override;

    /**
     * @brief Compute the score based on the card the user is dealt.
     *      
     */
    void hit(Deck& deck) override;
};

#endif
