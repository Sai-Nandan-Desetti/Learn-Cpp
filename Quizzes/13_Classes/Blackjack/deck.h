/**
 * @file deck.h
 * @author DSN
 * @brief Defines a \c Deck of cards
 * @version 0.2
 * @date 2023-08-19
 * 
 */

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <array>

/**
 * @brief A deck has \c 52 cards.
 * 
 */
constexpr std::size_t numCards{ 52 };
using CardArray = std::array<Card, numCards>;

class Deck
{
private:
    CardArray m_deck{};
    std::size_t m_cardIndex{ 0 };

public:
    /**
     * @brief Initialize the deck of cards
     * 
     */
    Deck();
    
    void print() const;

    /**
     * @brief Shuffle the deck
     * 
     */
    void shuffle();

    /**
     * @brief Deal a card (the top one) from the deck
     * 
     * @return const Card&: a constant reference to the dealt card
     */
    const Card& dealCard();
};

#endif
