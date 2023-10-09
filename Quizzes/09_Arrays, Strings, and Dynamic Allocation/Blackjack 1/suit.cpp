#include "suit.h"

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

int getValue(const CardSuit suit)
{
    return static_cast<int>(suit);
}

std::size_t getNumSuits()
{
    return static_cast<std::size_t>(max_suits);
}
