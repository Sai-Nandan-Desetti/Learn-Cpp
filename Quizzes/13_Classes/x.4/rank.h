/**
 * @file rank.h
 * @author DSN
 * @brief Defines \c CardRank
 * @version 0.3
 * @date 2023-08-19
 * 
 */

#ifndef RANK_H
#define RANK_H

#include <cstddef>
#include <iostream>

/**
 * @brief The rank of a card
 * 
 */
enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

using enum CardRank;

/**
 * @brief Get a character representation of a card's rank. 
 * @param rank
 * @return char
 */
char getName(const CardRank rank);

/**
 * @brief Given an integer, get the corresponding rank enum
 * 
 * @param rank 
 * @return CardRank 
 */
CardRank getRank(std::size_t rank);

/**
 * @brief Get the numeric value of a card's rank.
 * @param rank
 * @return int
 */
int getValue(const CardRank rank);

/**
 * @brief An auxiliary function that defines an upper bound on the number of ranks a deck of cards can have.
 * 
 * @return std::size_t: \c max_ranks 
 */
std::size_t getNumRanks();

/**
 * @brief Overloads \c << to print the rank of a card
 * 
 * @param out 
 * @param obj 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const CardRank& rank);

#endif
