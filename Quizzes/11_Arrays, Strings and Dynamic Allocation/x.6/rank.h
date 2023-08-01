#ifndef RANK_H
#define RANK_H

#include <cstddef>

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

char getName(const CardRank);
int getValue(const CardRank);
std::size_t getNumRanks();

#endif
