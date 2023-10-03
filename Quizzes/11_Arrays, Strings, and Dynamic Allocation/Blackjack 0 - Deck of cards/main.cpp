#include "deck.h"
#include <iostream>

int main()
{    
    Deck deck{ createDeck() };
    printDeck(deck);        
    
    std::cout << "\nThe deck shuffled:\n";
    shuffleDeck(deck);
    printDeck(deck);

    std::cout <<"\nValue of the first card: " << getCardValue(deck[0]) << '\n';    

    return 0;
}
