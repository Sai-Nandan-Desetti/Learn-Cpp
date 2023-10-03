/**
 * @file suit.h
 * @author DSN
 * @brief Defines \c CardSuit
 * @version 0.1
 * @date 2023-08-19
 *
 */

#ifndef SUIT_H
#define SUIT_H

#include <cstddef>
#include <iostream>

/**
 * @brief The suit of a card
 * 
 */
enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

using enum CardSuit;

/**
 * @brief Get the string representation of a card's suit
 * 
 * @return char 
 */
char getName(const CardSuit);

/**
 * @brief Given a suit, return its corresponding suit enum
 * 
 * @param suit 
 * @return CardSuit 
 */
CardSuit getSuit(std::size_t suit);

/**
 * @brief Get the numeric value of a card's suit
 * 
 * @return int 
 */
int getValue(const CardSuit);

/**
 * @brief Get the max number of suits a deck of cards can have
 * 
 * @return std::size_t 
 */
std::size_t getNumSuits();

/**
 * @brief Overloads \c << to print the suit of a card
 * 
 * @param out 
 * @param suit 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const CardSuit& suit);

#endif
