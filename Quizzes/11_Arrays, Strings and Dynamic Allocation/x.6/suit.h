#ifndef SUIT_H
#define SUIT_H

#include <cstddef>

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

using enum CardSuit;

char getName(const CardSuit);
int getValue(const CardSuit);
std::size_t getNumSuits();

#endif
