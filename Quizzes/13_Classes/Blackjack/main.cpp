/**
 * @file main.cpp
 * @author DSN
 * @brief Play a game of Blackjack
 * @version 0.3
 * @date 2023-08-19
 * 
 */

/**
 * @mainpage 
 * A simplified version of Blackjack.
 * \n
 * <b>Rules</b>:
 *  - There are two kinds of \c Player: \c Dealer and \c User
 *  - The dealer gets one card to start
 * (in real life, the dealer gets two, but one is face down so it doesn’t matter at this point).
 *  - Users gets two cards to start.
 *  - Dealer goes last.
 *  - A player can repeatedly “hit” or “stand”.
 *  - If the player “stands”, their turn is over, and their score is calculated based on the cards they have been dealt.
 *  - If the player “hits”, they get another card and the value of that card is added to their total score.
 *  - An ace normally counts as a 1 or an 11 (whichever is better for the total score). 
 *  - If a player goes over a score of 21, they bust and lose immediately. 
 *  - The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand. 
 *  - Otherwise, the player with the highest score wins.
 *      - We don't consider ties for simplicity.
 *      - So, it can happen that both multiple players can win.
 * \n
 * <p>
 * In our simplified version of Blackjack, we’re not going to keep track of which specific cards a player has been dealt.
 * We’ll only track the sum of the values of the cards.
 * \n 
 *  
 */

#include "blackjack.h"
#include "user.h"
#include "dealer.h"
#include "io.h"
#include <cstdlib>


/**
 * @details
 * - Setup the players
 *  - Why don't we setup the players in a separate function or a separate "Service" class?
 *      - Note that the lifetimes of the \c dealer and the \c user(s) must be that of the entire program.
 *      - As long as the program is running, the game is being played; for which the players must naturally be alive!
 *  - The \c User needs to be informed of the \c playerLimit.
 *  - The \c Dealer will be told the \c dealerLimit as well.
 * - Play a game of Blackjack
 * - Reset the players
 *  - In case the players want to play another round.
 * 
 * @return int 
 */
int main()
{               
    Dealer dealer{ Dealer(playerLimit, dealerLimit) };
    User user{ User(playerLimit) };
    Players players{ &dealer, &user };    
    
    Blackjack game{ Blackjack(players) };

    char choice{};

    do
    {   
        std::cout << "\nLet's play Blackjack!\n";
        std::cout << "Press any key to start the game.\n";             
        std::cin >> choice;
        inputCleanup();
        
        system("cls");

        game.play();
        game.displayResult();
        game.resetPlayers(); // in case the user want to play another round

        do
        {
            std::cout << "\nDo you want to play again? (y/n)\n";
            std::cin >> choice;
            inputCleanup();
            // ensure that the user enters an appropriate choice
        } while (not (choice == 'y' or choice == 'n'));                

    } while (choice == 'y');
    
    std::cout << "\nThanks for visiting... Bye!\n";

    return 0;
}
