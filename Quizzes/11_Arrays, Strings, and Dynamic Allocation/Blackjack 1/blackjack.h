#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"

enum Outcome
{
    DEALER_WINS,
    USER_WINS    
};

Outcome playBlackjack(const Deck& deck);

#endif
