/**
 * @file main.cpp
 * @author DSN
 * @brief A Blackjack game application
 * @version 0.2
 * @date 2023-07-09
 * 
 */

/**
 * @mainpage 
 * Let’s write a simplified version of Blackjack.
 * If you’re not already familiar with Blackjack, the Wikipedia article for [Blackjack]() has a summary.
 * \n
 * Here are the rules for our version of Blackjack:
 *  - The dealer gets one card to start
 * (in real life, the dealer gets two, but one is face down so it doesn’t matter at this point).
 *  - The player gets two cards to start.
 *  - The player goes first.
 *  - A player can repeatedly “hit” or “stand”.
 *  - If the player “stands”, their turn is over, and their score is calculated based on the cards they have been dealt.
 *  - If the player “hits”, they get another card and the value of that card is added to their total score.
 *  - An ace normally counts as a 1 or an 11 (whichever is better for the total score).
 * For simplicity, we’ll count it as an 11 here.
 *  - If the player goes over a score of 21, they bust and lose immediately.
 *  - The dealer goes after the player.
 *  - The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
 *  - If the dealer goes over a score of 21, they bust and the player wins immediately.
 *  - Otherwise, if the player has a higher score than the dealer, the player wins.
 * Otherwise, the player loses (we’ll consider ties as dealer wins for simplicity).
 * \n
 * <p>
 * In our simplified version of Blackjack,
 * we’re not going to keep track of which specific cards the player and the dealer have been dealt.
 * We’ll only track the sum of the values of the cards they have been dealt for the player and the dealer.
 * This keeps things simpler.
 * \n
 * Create a function named \c playBlackjack(). This function should:
 *  - Accept a shuffled deck of cards as a parameter.
 *  - Implement Blackjack as defined above (note: you can define other functions to help with this).
 *  - Returns true if the player won, and false if they lost.
 *  
 */

#include "blackjack.h"
#include <iostream>

/**
 * @brief Create a deck of cards, shuffle it and play a game of Blackjack; display if the user won or lost.
 * 
 * @return int: 0 
 */
int main()
{
    Deck deck{ createDeck() };        
    shuffleDeck(deck);    

    Outcome outcome { playBlackjack(deck) };
    switch (outcome)
    {
    case USER_WINS:
        std::cout << "\nYou WON!\n";
        break;
    case NEITHER_WINS:
        std::cout << "\nIt's a TIE!\n";
        break;
    default:
        std::cout << "\nSorry. You lost.\n";
        break;
    }

    return 0;
}
