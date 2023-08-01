/**
 * @file main.cpp
 * @author DSN
 * @brief Print `a` to `z` long with their ASCII codes
 * @version 0.1
 * @date 2023-07-03
 * 
 */

/**
 * @mainpage
 * Write a program that prints out the letters a through z along with their ASCII codes.
 */


#include <iostream>

int main()
{
    char c { 'a' };
    while (c <= 'z')
    {
        std::cout << c << '\t' << static_cast<unsigned int>(c) << '\n';
        c++;
    }

    return 0;
}
