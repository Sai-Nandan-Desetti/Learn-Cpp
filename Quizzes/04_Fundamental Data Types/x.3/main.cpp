/**
 * @file main.cpp
 * @author DSN
 * @brief A calculator that supports the following operations: +, -, *, /
 * @version 0.1
 * @date 2023-06-29
 *  
 */

/**
 * @mainpage
 * <b>Chapter</b> [4.x](https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/)
 * \n
 * Write the following program: 
 *  - The user is asked to enter 2 floating point numbers (use doubles).
 *  - The user is then asked to enter one of the following mathematical symbols: +, -, *, or /.
 *  - The program computes the answer on the two numbers the user entered and prints the results.
 *  - If the user enters an invalid symbol, the program should print nothing.
 */


#include "operations.h"
#include "io.h"
#include <iostream>


int main()
{
    double x{ getNumber() }, y{ getNumber() };

    std::cout << "Enter one of the following operations: +, -, *, or /" << '\n';
    char op{};
    std::cin >> op;

    double result{};

    if (op == '+')
        result = add(x, y);
    else if (op == '-')
        result = subtract(x, y);
    else if (op == '*')
        result = multiply(x, y);
    else if (op == '/')
        result = divide(x, y);

    printResult(result);

    return 0;
}
