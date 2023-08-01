/**
 * @file io.cpp
 * @author DSN
 * @brief Contains functions relating to input/output.
 * @version 0.1
 * @date 2023-06-29
 *  
 */


#include <iostream>


double getNumber()
{
    std::cout << "Enter a number: ";
    double input{};
    std::cin >> input;

    return input;
}


void printResult(double result)
{
    std::cout << "Result: " << result << std::endl;
}
