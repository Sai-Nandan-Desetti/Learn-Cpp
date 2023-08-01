/**
 * @file io.cpp
 * @author DSN
 * @brief This file contains the function definitions used in \c main.cpp
 * @version 0.1
 * @date 2023-06-28
 * 
 */

// include section
#include <iostream>

/**
 * @details 
 * The integer is read from the standard input stream.
 * 
 * @return The integer read from the user.
 */
int readNumber()
{
    int input{};
    std::cout << "Enter a number: " << "\n";
    std::cin >> input;

    return input;
}

/**
 * @details 
 * The integer is output to the standard output stream.
 * \n It's semantically assumed that this function is called to display an \c output.
 * 
 * @param output: The integer to be displayed. 
 */
void writeAnswer(int output)
{
    std::cout << "Output: " << output << "\n";    
}
