#include "card.h"
#include "io.h"
#include <iostream>

void makeCard(Card& card, std::size_t suit, std::size_t rank)
{
    card.suit = static_cast<CardSuit>(suit);
    card.rank = static_cast<CardRank>(rank);
}

void printCard(const Card& card)
{
    std::cout << card.rank << card.suit;
}

int getValue(const Card& card)
{
    return getValue(card.rank);
}
