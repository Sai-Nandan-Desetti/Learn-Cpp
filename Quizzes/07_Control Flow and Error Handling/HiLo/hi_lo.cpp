/**
 * @file hi_lo.cpp
 * @author DSN
 * @brief This file contains functions that help simulate the game of Hi-Lo.
 * @version 0.1
 * @date 2023-07-04
 *
 */

#include "Random.h"
#include "io.h"
#include <iostream>
#include <string_view>

int thinkOfANumber(int min, int max)
{
    return Random::get(min, max);
}

int getUserGuess(int guess_no)
{
    int guess{};
    do
    {
        std::cout << "Guess #" << guess_no << ": ";
        std::cin >> guess;
        inputCleanup();

    } while (guess < 1 || guess > 100);

    return guess;
}

bool hi_lo(int systemNumber, int userGuess)
{
    if (systemNumber == userGuess)
        return true;

    std::string_view result{userGuess > systemNumber ? "high" : "low"};
    std::cout << "Your guess is too " << result << ".\n";
    return false;
}
