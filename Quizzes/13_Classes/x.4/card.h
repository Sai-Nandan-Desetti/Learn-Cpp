/**
 * @file card.h
 * @author DSN
 * @brief Defines a \c Card
 * @version 0.3
 * @date 2023-08-19
 * 
 */

#ifndef CARD_H
#define CARD_H

#include "rank.h"
#include "suit.h"
#include <iostream>

/**
 * @brief A \c Card is defined by its rank (see \c CardRank) and suit (see \c CardSuit).
 * 
 */
class Card
{
private:
    CardRank m_rank{};
    CardSuit m_suit{};    

public:    
    Card(CardRank rank = rank_ace, CardSuit suit = club);
    
    /**
     * @brief Get the value of a \c Card
     * 
     * @return int 
     */
    int getCardValue() const;

    /**
     * @brief Get the card's rank
     * 
     * @return CardRank 
     */
    CardRank getRank() const;

    /**
     * @brief Overload \c << to print a \c Card
     * 
     * @param out 
     * @param card 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};

#endif
