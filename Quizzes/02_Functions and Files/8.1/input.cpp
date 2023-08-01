#include <iostream>

/**
 * @brief Get an integer from the user.
 * @details We take input from the standard input stream.
 * @return The integer entered by the user.
 */
int getInteger()
{
    std::cout << "Enter a number: ";
    int input{};
    std::cin >> input;

    return input;    
}
