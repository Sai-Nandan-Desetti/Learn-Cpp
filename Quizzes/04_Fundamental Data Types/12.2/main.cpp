/**
 * @file main.cpp
 * @author DSN
 * @brief Display the value and ASCII code of a character entered by the user.
 * @details Use implicit conversion to get the ASCII code.
 * @version 0.1
 * @date 2023-06-28
 *
 */

#include <iostream>

int main()
{
    std::cout << "Enter character: ";
    char c{};
    std::cin >> c;

    int ascii{c};
    std::cout << "You entered the character: "
              << "'" << c << "'"
              << ", which has ASCII code " << ascii << "." << std::endl;
}
