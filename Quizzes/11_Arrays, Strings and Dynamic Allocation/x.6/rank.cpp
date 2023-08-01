#include "rank.h"

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

std::size_t getNumRanks()
{
    return static_cast<std::size_t>(CardRank::max_ranks);
}
