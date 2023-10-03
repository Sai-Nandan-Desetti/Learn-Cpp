/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Demonstrate a game of Fizz Buzz
 * @version 0.1
 * @date 2023-07-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @mainpage
 * [Fizz Buzz](https://en.m.wikipedia.org/wiki/Fizz_buzz) is a simple math game used to teach children about divisibility.
 * It is also sometimes used as an interview question to assess basic programming skills.
 * \n
 * The rules of the game are simple:
 *  - Starting at 1, and counting upward, replace any number divisible <em>only</em> by three with the word “fizz”,
 * any number <em>only</em> divisible by five with the word “buzz”,
 * and any number divisible by <em>both</em> 3 and 5 with the word “fizzbuzz”.
 *  - Implement this game inside a function named \c fizzbuzz() that takes a parameter determining
 * what number to count up to.
 * \n
 * The output of \c fizzbuzz(15) should match the following:
    @verbatim
    1
    2
    fizz
    4
    buzz
    fizz
    7
    8
    fizz
    buzz
    11
    fizz
    13
    14
    fizzbuzz
    @endverbatim
 */


#include <iostream>


void fizzbuzz(unsigned int n)
{
    for (unsigned int i{1}; i <= n; ++i)
    {
        if (i % 15 != 0)
        {
            if (i % 3 == 0)
                std::cout << "fizz";
            else if (i % 5 == 0)
                std::cout << "buzz";
            else if (i % 7 == 0)
                std::cout << "pop";
            else
                std::cout << i;
        }
        else
            std::cout << "fizzbuzz";

        std::cout << '\n';
    }
}


int main()
{
    std::cout << "Enter the parameter till when you want the game to continue: ";
    unsigned int n {};
    std::cin >> n;

    fizzbuzz(n);

    return 0;
}
