/**
 * @file card.cpp
 * @author DSN
 * @brief Defines member and friend functions of \c Card
 * @version 0.3
 * @date 2023-08-19
 * 
 */

#include "card.h"


Card::Card(CardRank rank, CardSuit suit)
{
    m_suit = static_cast<CardSuit>(suit);
    m_rank = static_cast<CardRank>(rank);
}

/**
 * @details The value of a card is the value of its rank
 * 
 * @return int 
 */
int Card::getCardValue() const
{
    return getValue(m_rank);
}

CardRank Card::getRank() const
{
    return m_rank;
}

/**
 * @details This function is declared as a friend of \c Card so that we can directly 
 * access its private members: \c m_rank and \c m_suit.
 * 
 */
std::ostream& operator<<(std::ostream& out, const Card& card)
{
    return out << card.m_rank << card.m_suit;
}

