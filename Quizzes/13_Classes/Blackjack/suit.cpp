/**
 * @file suit.cpp
 * @author DSN
 * @brief Defines functions pertaining to a card's suit
 * @version 0.1
 * @date 2023-08-19
 * 
 */

#include "suit.h"

/**
 * @details
 * - The string representations of the club, diamond, heart, and spade suits are
 * 'C', 'D', 'H', and 'S', respectively.
 * - For an invalid suit, \c ? is returned.
 */
char getName(const CardSuit suit)
{
    switch (suit)
    {
    case club:
        return 'C';
    case diamond:
        return 'D';
    case heart:
        return 'H';
    case spade:
        return 'S';
    default:
        return '?';
    }
}

/**
 * @details Type-cast \c suit to \c CardSuit
 * 
 */
CardSuit getSuit(std::size_t suit)
{
    return static_cast<CardSuit>(suit);
}

/**
 * @details \c suit is an enumeration; so, it's type-casted to an \c int
 */
int getValue(const CardSuit suit)
{
    return static_cast<int>(suit);
}

/**
 * @details \c max_suits is an enumeration; so, it's type-casted to \c std::size_t 
 */
std::size_t getNumSuits()
{
    return static_cast<std::size_t>(max_suits);
}


std::ostream& operator<<(std::ostream& out, const CardSuit& suit)
{
    return out << getName(suit);
}
