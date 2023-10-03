/**
 * @file main.cpp
 * @author DSN
 * @brief Calculate the integral result of the given operation
 * @version 0.1
 * @date 2023-07-03
 * 
 */

/**
 * @mainpage
 * Write a function called \c calculate() that takes two integers and a character
 * representing one of the following mathematical operations: +, -, *, /, or % (remainder).
 *  - Use a \c switch statement to perform the appropriate mathematical operation on the integers,
 * and return the result.
 *  - If an invalid operator is passed into the function, the function should print an error message.
 *  - For the division operator, do an integer division.
 * 
 */


#include <iostream>


void calculate(int x, int y)
{
    std::cout << "Enter the operation (+, -, *, /, %): ";
    char op {};
    std::cin >> op;
    
    switch(op)
    {
        case '+': std::cout << "x + y = " << x + y << '\n'; return;
        case '-': std::cout << "x - y = " << x - y << '\n'; return;
        case '*': std::cout << "x * y = " <<  x * y << '\n'; return;
        case '/': std::cout << "x / y = " << x / y << '\n'; return;
        case '%': std::cout << "x % y = " << x % y << '\n'; return;
        default: std::cout << "Invalid operation!\n"; return;           
    }
}


int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    calculate(x, y);

    return 0;
}
