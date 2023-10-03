/**
 * @file main.cpp
 * @author DSN
 * @brief Display the value and ASCII code of a character entered by the user.
 * @details Use explicit conversion to get the ASCII code.
 * @version 0.1
 * @date 2023-06-28
 *
 */

#include <iostream>

int main()
{
    std::cout << "Enter a character: ";
    char c{};
    std::cin >> c;

    std::cout << "You entered "
              << "'" << c << "'"
              << ", which has an ASCII code of " << static_cast<int>(c) << '.' << std::endl;

    return 0;
}
