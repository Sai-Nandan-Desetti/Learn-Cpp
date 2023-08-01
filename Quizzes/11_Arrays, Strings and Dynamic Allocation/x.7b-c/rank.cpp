/**
 * @file rank.cpp
 * @brief Defines functions pertaining to a card's rank.
 * 
 */

#include "rank.h"

/**
 * @details
 * - The character representations of ranks 2 to 9 are the number itself in quotes.
 *  - Eg: A card with rank \c rank_5 has the character representation: '5'.
 * - The representations of the remaining ranks are listed below:
 *  - \c rank_10: 'T'
 *  - \c rank_jack: 'J'
 *  - \c rank_king: 'K'
 *  - \c rank_queen: 'Q'
 *  - \c rank_ace: 'A'
 * - The default representation is '?'.
 */
char getName(const CardRank rank)
{
    switch (rank)
    {
    case rank_2:
            return '2';
    case rank_3:
            return '3';
    case rank_4:
            return '4';
    case rank_5:
            return '5';
    case rank_6:
            return '6';
    case rank_7:
            return '7';
    case rank_8:
            return '8';
    case rank_9:
            return '9';
    case rank_10:
            return 'T';
    case rank_jack:
            return 'J';
    case rank_king:
            return 'K';
    case rank_queen:
            return 'Q';
    case rank_ace:
            return 'A';
    default:
            return '?';
    }
}

/**
 * @details
 * - The numeric value of ranks 2 to 9 are their straightforward numeric equivalents.
 *  - Eg: value of a card with rank 3 is 3.
 * - The value of cards with the remaining ranks are listed below:
 *  - Ranks 10, J, K, Q: 10
 *  - Rank A: 11 
 */
int getValue(const CardRank rank)
{
    switch (rank)
    {
    case rank_2:
    case rank_3:
    case rank_4:
    case rank_5:
    case rank_6:
    case rank_7:
    case rank_8:
    case rank_9:
            return static_cast<int>(rank) + 2;
    case rank_10:
    case rank_jack:
    case rank_king:
    case rank_queen:
            return static_cast<int>(rank_10) + 2;
    case rank_ace:
            return static_cast<int>(rank_10) + 3;            
    default:
            return -1;
    }
}

/**
 * @details
 * - \c max_ranks is of type \c CardRank; You've to typecast it to \c std::size_t.
 */
std::size_t getNumRanks()
{
    return static_cast<std::size_t>(CardRank::max_ranks);
}
