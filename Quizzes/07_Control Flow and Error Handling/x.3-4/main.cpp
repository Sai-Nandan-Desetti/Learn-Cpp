/**
 * @file main.cpp
 * @author DSN
 * @brief This file provides the interface for the Hi-Lo game
 * @version 0.1
 * @date 2023-07-04
 *
 */

#include "hi_lo.h"
#include "io.h"
#include <iostream>

int main()
{
    constexpr int min{1};
    constexpr int max{100};
    constexpr int maxGuesses{7};

    char option{};
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

    do
    {
        int systemNumber = thinkOfANumber(min, max);
        bool won{false};

        for (int guess_no{1}; guess_no <= maxGuesses && !won; ++guess_no)
        {
            int userGuess = getUserGuess(guess_no);
            won = hi_lo(systemNumber, userGuess);
        }

        if (won)
            std::cout << "Correct! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct number was " << systemNumber << ".\n";

        do
        {
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> option;
            inputCleanup();

        } while (option != 'y' && option != 'n');

    } while (option == 'y');

    std::cout << "Thank you for playing.\n";
}
