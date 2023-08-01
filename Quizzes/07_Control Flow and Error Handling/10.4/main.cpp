/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.2
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
 *  - Add the rule that numbers divisible by seven should be replaced with “pop”.
 *  - Implement this game inside a function named \c fizzbuzz() that takes a parameter determining
 * what number to count up to.
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

/* Version 0.1 */
#if 0
void fizzbuzz(unsigned int n)
{
    for (unsigned int i{1}; i <= n; ++i)
    {
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            if (i % 5 == 0)
                std::cout << "buzz";
            if (i % 7 == 0)
                std::cout << "pop";                        
        }

        else if (i % 5 == 0)
        {
            std::cout << "buzz";
            if (i % 7 == 0)
                std::cout << "pop";
        }

        else if (i % 7 == 0)
            std::cout << "pop";

        else
            std::cout << i;

        std::cout << '\n';
    }
}
#endif

/* Version 0.2 */

/**
 * @brief Play the Fizz Buzz game upto \c n
 * @details
 * - We are allowed to use only 1 \c if per divisor.
 * 
 * - Observe how we're expected to print the output for 15 for example:
 *  - 15: "fizzbuzz"
 *  1. We check if 15 is divisble by 3 and then print "fizz" immediately.
 *  2. Check if it's divisible by 5 and then print "buzz" immediately.
 * - So, note that as and when we find if a number is divisble by 3, 5, or 7,
 * we display the corresponding term immediately.
 * 
 * - Use a boolean variable \c divisible to determine if a number is not divisble by
 * any of those divisors.
 *  - If not, display the number itself.
 * 
 * - At the end of each iteration,
 *  - \c divisible must be reset to \c false.
 *  - print a newline
 * 
 * @param n: the extent to which the game must be continued
 */
void fizzbuzz(unsigned int n)
{
    bool divisible { false };

    for (unsigned int i{1}; i <= n; ++i, divisible = false)
    {
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            divisible = true;
        }

        if (i % 5 == 0)
        {
            std::cout << "buzz";
            divisible = true;            
        }

        if (i % 7 == 0)
        {
            std::cout << "pop";
            divisible = true;
        }

        if (!divisible)        
            std::cout << i;        
        
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
