/**
 * @file io.cpp
 * @author DSN
 * @brief Handles I/O
 * @date 2023-06-29
 * 
 */

#include <iostream>
#include <string_view>


double getInput(std::string_view message)
{
    std::cout << message;
    double input{};
    std::cin >> input;

    return input;
}


void printBallHeight(const double seconds, const double height)
{
    std::cout << "At " << seconds << " seconds, "
              << "the ball is at height: " << height << " meters\n";
}


void printReached(const double seconds)
{
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}


void printResult(const double seconds, const double height)
{
    if (height > 0)
        printBallHeight(seconds, height);
    
    else
        printReached(seconds);
}
