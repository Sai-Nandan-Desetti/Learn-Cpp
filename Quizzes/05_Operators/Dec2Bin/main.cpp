/**
 * @file main.cpp
 * @author DSN
 * @brief Convert a decimal number [0, 255] to binary without using any binary operators or the bitset library.
 * @version 0.1
 * @date 2023-07-01
 * 
 */

/**
 * @mainpage
 * \n
 * <b>Chapter</b> [O.4](https://www.learncpp.com/cpp-tutorial/converting-integers-between-binary-and-decimal-representation/)
 * \n
 * - Write a program that asks the user to input a number between 0 and 255.
 * - Print this number as an 8-bit binary number (of the form #### ####).
 * - Don’t use any bitwise operators.
 * - Don’t use \c std::bitset.
 */

#include <cmath>
#include <string>
#include <iostream>


std::string dec2Bin(unsigned int n)
{
    std::string bin{ "0000 0000" };

    if (n >= 128)
    {
        bin[0] = '1';
        n -= 128;
    }

    if (n >= 64)
    {
        bin[1] = '1';
        n -= 64;
    }

    if (n >= 32)
    {
        bin[2] = '1';
        n -= 32;
    }

    if (n >= 16)
    {
        bin[3] = '1';
        n -= 16;
    }

    // leave a space in bin

    if (n >= 8)
    {
        bin[5] = '1';
        n -= 8;
    }

    if (n >= 4)
    {
        bin[6] = '1';
        n -= 4;
    }

    if (n >= 2)
    {
        bin[7] = '1';
        n -= 2;
    }

    if (n > 0)
    {
        bin[8] = '1';        
    }

    return bin;                    
}


int main()
{
    std::cout << "Enter a decimal number between [0, 255]: ";
    unsigned int n{};
    std::cin >> n;

    std::cout << "The binary representation of " << n << ":\n";
    std::cout << dec2Bin(n) << '\n';

    return 0;
}
