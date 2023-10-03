/**
 * @file main.cpp
 * @author DSN
 * @brief Checks whether the number input by the user is even or odd.
 * @version 0.1
 * @date 2023-06-29
 * 
 */

/**
 * @mainpage
 * \n
 * <b>Chapter</b> [3.2](https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/)
 * Write a program that asks the user to input an integer,
 * and tells the user whether the number is even or odd.
 *  - Write a function called \c isEven() that returns
 *    \c true if an integer passed to it is even, and \c false otherwise.
 *  - Use the remainder operator to test whether the integer parameter is even.
 *  - Make sure \c isEven() works with both positive and negative numbers.
 * \n
 * Your program should match the following output:
    @verbatim
    Enter an integer: 5
    5 is odd
    @endverbatim
 * 
 */


#include <iostream>


bool isEven(const int n)
{
    return (n % 2) == 0;
}


int main()
{
    std::cout << "Enter an integer: ";
    int n{};
    std::cin >> n;

    if (isEven(n))
        std::cout << n << " is even\n";
    else
        std::cout << n << " is odd\n";
}
