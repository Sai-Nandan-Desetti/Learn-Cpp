/**
 * @file func.cpp
 * @author DSN
 * @brief What happens when you use a function without calling it?
 * @version 0.1
 * @date 2023-06-27
 * 
 */

// Include section
#include <iostream>

// Function section
/**
 * @brief A test function.
 * 
 * @return the literal @c 5
 * 
 */
int returnFive()
{
    return 5;
}

// main section
int main() 
{   
    // This is a warning.
    // If you compile without the "-Werror" flag, then you can run this program.
    std::cout << returnFive << "\n";

    // Upon execution, the value printed was 1, everytime.
}
