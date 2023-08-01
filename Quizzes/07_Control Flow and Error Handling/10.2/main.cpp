/**
 * @file main.cpp
 * @author DSN
 * @brief Given an integer \c n, displays the sum: 1 + 2 + ... n
 * @version 0.2
 * @date 2023-07-03
 * 
 */

/**
 * @mainpage
 * Write a function named \c sumTo() that takes an integer parameter \c n,
 * and returns the sum of all the numbers from \c 1 to \c n.
*/


#include <iostream>

/**
 * @brief Computes the sum: 1 + 2 + ... + n
 * 
 * @param n 
 * @return The computed \c total
 */
unsigned int sumTo(unsigned int n)
{
    unsigned total {};
    for (unsigned int i = 1; i <= n; ++i)    
        total += i;

    return total;
}


/**
 * @brief Checks if the input \c n is valid or not and displays the desired sum.
 * @details The input is valid if \c n \c > \c 1, otherwise not.
 * @return 0 
 */
int main()
{
    unsigned int n {};
    do{
        std::cout << "Enter an integer (> 1): ";
        std::cin >> n;

    } while (n < 1);

    std::cout << "The sum fron 1 to "<< n << " = " << sumTo(n) << '\n';

    return 0;
}
