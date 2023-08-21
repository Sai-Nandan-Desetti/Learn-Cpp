/**
 * @file deck.cpp
 * @author DSN
 * @brief Defines member functions of \c Deck
 * @version 0.2
 * @date 2023-08-19
 * 
 */

#include "deck.h"
#include <random>
#include <ctime>
#include <algorithm>
#include <iostream>

/**
 * @details
 * Create 52 cards to initialize the deck
 * 
 */
Deck::Deck()
{
    using Index = CardArray::size_type;
    Index index{ 0 };

    for (std::size_t suit{ 0 }; suit < getNumSuits(); ++suit)        
        for (std::size_t rank{ 0 }; rank < getNumRanks(); ++rank)
            m_deck[index++] = Card(getRank(rank), getSuit(suit));
}

void Deck::print() const
{
    for (auto& card : m_deck)    
        std::cout << card << ' ';    
}

/**
 * @details
 *  - Uses a Mersenne Twister to arrange the deck in a random order
 *  - Sets \c m_cardIndex to 0.
 * 
 */
void Deck::shuffle()
{
    // static so that it gets seeded only once
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    
    m_cardIndex = 0;
}

/**
 * @details
 *  - Deals a card pointed to by \c m_cardIndex
 * 
 */
const Card& Deck::dealCard()
{            
    return m_deck[m_cardIndex++];
}
