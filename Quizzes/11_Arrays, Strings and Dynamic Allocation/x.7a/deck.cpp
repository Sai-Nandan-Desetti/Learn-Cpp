#include "deck.h"
#include <random>
#include <ctime>
#include <algorithm>
#include <iostream>

Deck createDeck()
{
    Deck deck{};
    
    using Index = Deck::size_type;
    Index index{0};

    for (std::size_t suit{0}; suit < getNumSuits(); ++suit)        
        for (std::size_t rank{0}; rank < getNumRanks(); ++rank)
            makeCard(deck[index++], suit, rank);

    return deck;               
}

void printDeck(const Deck& deck)
{
    for (auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }        
}

void shuffleDeck(Deck& deck)
{
    // static so that it gets seeded only once
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
}
