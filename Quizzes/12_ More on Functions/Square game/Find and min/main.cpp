/**
 * @file main.cpp
 * @author DSN
 * @brief Play a game based on squares
 * @details
 *  - Find the guess
 *  - If not found, then find one closest to it
 * @version 0.1
 * @date 2023-07-18
 * 
 */

#include "Random.h"
#include <vector>
#include <iostream>


int main()
{
    std::cout << "Start where? ";
    int lo{};
    std::cin >> lo;

    std::cout << "How many? ";
    int n;
    std::cin >> n;

    int multiple{Random::get(2, 4)};
            
    using Size = std::vector<int>::size_type;
    std::vector<int> squareMultiples(static_cast<Size>(n));
    
    auto generateMultipleOfSquares{
        [=](auto& squareMultiples)
        {            
            using Index = std::vector<int>::size_type;

            for (int i{0}; i < n; ++i)
                squareMultiples[static_cast<Index>(i)] = ((lo + i) * (lo + i)) * multiple;
        }
    };
    generateMultipleOfSquares(squareMultiples);

    std::cout << "I generated " << n << " square number(s). Do you know what each number is after multiplying by " << multiple << "?\n";

    int guess{};
    while (true)
    {
        std::cout << "Your guess: ";
        std::cin >> guess;
        
        auto found{ std::find(squareMultiples.begin(), squareMultiples.end(), guess) };
        if (found != squareMultiples.end())
        {
            std::cout << "Nice! ";

            squareMultiples.erase(found);
            if (not squareMultiples.empty())
            {
                std::cout << squareMultiples.size() << " number(s) left.\n";
            }                
            else
            {
                std::cout << "You found all numbers, good job!\n";
                break;
            }
        }
        else
        {
            auto distFromGuess{
                [=](int self, int other) -> bool
                {
                    return abs(self - guess) < abs(other - guess);
                }
            };            
            auto closestSquare{ std::min_element(squareMultiples.begin(), squareMultiples.end(), distFromGuess) };

            if (closestSquare != squareMultiples.end())
            {
                std::cout << guess << " is wrong! Try " << *closestSquare << " next time.\n";
            }                
            else
            {
                std::cout << guess << " is wrong!\n";
                break;
            }
        }
    }

    return 0;
}
