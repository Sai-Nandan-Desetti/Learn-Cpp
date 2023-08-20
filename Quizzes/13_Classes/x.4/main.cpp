/**
 * @file main.cpp
 * @author DSN
 * @brief Play a game of Blackjack
 * @version 0.3
 * @date 2023-08-19
 * 
 */

#include "blackjack.h"
#include "user.h"
#include "dealer.h"
#include "io.h"
#include <cstdlib>


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
        game.resetPlayers();

        do
        {
            std::cout << "\nDo you want to play again? (y/n)\n";
            std::cin >> choice;
            inputCleanup();
        } while (not (choice == 'y' or choice == 'n'));                

    } while (choice == 'y');
    
    std::cout << "\nThanks for visiting... Bye!\n";

    return 0;
}
