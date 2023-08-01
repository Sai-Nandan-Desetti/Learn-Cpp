/**
 * @file main.cpp
 * @author DSN
 * @brief Reads two integers from the user and displays their sum. 
 * @version 0.1
 * @date 2023-06-27
 * 
 */

/**
 * @mainpage
 * <b>Chapter</b> [2.x](https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/) 
 * \n 
 * Q1: Write a single-file program (named \c main.cpp) that reads two separate integers from the user,
 * adds them together, and then outputs the answer. 
 * The program should use three functions:
 * - A function named \c readNumber() should be used to get (and return) a single integer from the user.
 * - A function named \c writeAnswer() should be used to output the answer.
 * This function should take a single parameter and have no return value.
 * - A \c main() function should be used to glue the above functions together.
*/

// include section
#include <iostream>


// function prototypes

/**
 * @brief Reads an integer from the user.
 * 
 */
int readNumber();

/**
 * @brief Displays an integer in the terminal.
 *  
 */
void writeAnswer(int output);


// main section
int main()
{
    int x{ readNumber() }, y{ readNumber() };
    writeAnswer(x + y);

    return 0;
}


// function definitions

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
