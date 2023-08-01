/**
 * @file main.cpp
 * @author DSN
 * @brief Take in two integers and find the smaller and the larger one.
 * @version 0.1
 * @date 2023-07-01
 *  
 */

/**
 * @mainpage
 * \n
 * <b>Chapter</b> [6.3](https://www.learncpp.com/cpp-tutorial/local-variables/)
 * \n
 * Q1: Write a program that asks the user to enter two integers,
 * one named \c smaller, the other named \c larger.
 *  - If the user enters a smaller value for the second integer,
 * use a block and a temporary variable to swap the \c smaller and \c larger values.
 *  - Then print the values of the \c smaller and \c larger variables.
 *  - Add comments to your code indicating where each variable dies.
 * \n
 * <b>Note</b>: When you print the values, \c smaller should hold the smaller input and 
 * \c larger the larger input, no matter which order they were entered in.
 */


#include <iostream>


int main()
{
    std::cout << "Enter an integer: ";
    int smaller {};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;

    if (smaller > larger)    
    {   
        std::cout << "Swapping the values\n";
                
        int temp { smaller };
        smaller = larger;
        larger = temp;
    } // temp dies here

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
} // smaller and lager die here
