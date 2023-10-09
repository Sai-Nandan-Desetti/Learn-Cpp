#ifndef CARD_H
#define CARD_H

#include "rank.h"
#include "suit.h"

struct Card
{
    CardSuit suit{};
    CardRank rank{};    
};

void makeCard(Card& card, std::size_t suit, std::size_t rank);
void printCard(const Card&);
int getCardValue(const Card& card);

#endif
