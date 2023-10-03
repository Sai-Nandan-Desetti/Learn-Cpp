/**
 * @file dealer.cpp
 * @author DSN
 * @brief Defines the member functions of \c Dealer
 * @version 0.1
 * @date 2023-08-19
 * 
 */

#include "dealer.h"


void Dealer::chance(Deck& deck)
{                
    if (m_score >= m_dealerLimit)
        m_stand = true;
    else
        hit(deck);                

    if (m_score > m_limit)
        m_busted = true;
}

void Dealer::hit(Deck& deck)
{
    const Card card{ deck.dealCard() };      

    m_score += card.getCardValue();
    if (card.getRank() == rank_ace and m_score > m_limit)
        m_score -= 10;
}
