/**
 * @file dealer.h
 * @author DSN
 * @brief Defines the \c Dealer
 * @version 0.2
 * @date 2023-08-19
 * 
 */

#ifndef DEALER_H
#define DEALER_H

#include "player.h"


class Dealer : public Player
{
    const int m_dealerLimit{};

public:
    Dealer(const int playerLimit, const int dealerLimit) : Player("Dealer", playerLimit), m_dealerLimit{ dealerLimit }
    {}

    /**
     * @brief Depending on the \c m_dealerLimit, the dealer can HIT or must STAND
     *  
     */
    void chance(Deck& deck) override;

    /**
     * @brief Compute the score based on the card the dealer gets
     * 
     * @param deck 
     */
    void hit(Deck& deck) override;
};

#endif
