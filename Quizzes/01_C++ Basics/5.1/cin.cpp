/**
 * @file cin.cpp
 * @author DSN
 * @brief Test various kinds of inputs to a variable declared as an integer.
 * 
 * This is Quiz question 1 in [lesson 1.5](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/).
 * 
 * @version 0.1
 * @date 2023-06-27
 * 
 */

#include <iostream>  // for std::cout and std::cin

int main()
{
    // ask user for a number
    std::cout << "Enter a number: ";
    
    // define variable x to hold user input
    int x{};
    
    // get number from keyboard and store it in variable x
    std::cin >> x;

    // display the number on the ouput console
    std::cout << "You entered " << x << '\n';

    return 0;
}
