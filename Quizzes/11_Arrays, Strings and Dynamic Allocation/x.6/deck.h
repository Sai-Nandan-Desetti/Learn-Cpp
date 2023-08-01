#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <array>

constexpr std::size_t numCards{52};
using Deck = std::array<Card, numCards>;

Deck createDeck();
void printDeck(const Deck&);
void shuffleDeck(Deck&);

#endif
