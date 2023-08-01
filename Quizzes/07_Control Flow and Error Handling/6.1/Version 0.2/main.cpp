/**
 * @file main.cpp
 * @author DSN
 * @brief Calculate the integral result of the given operation
 * @version 0.2
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
#include <optional>

/**
 * @brief Evaluate the operation \c op on \c x and \c y.
 * @details I haven't read about `std::optional` but it seems like it provides a way
 * of defining a function that can <em>optionally</em> return an integer.
 * 
 * @param x 
 * @param y 
 * @param op 
 * @return Return the result of the operation if the operation is valid, else an "empty" value.
 */
std::optional<int> calculate(int x, int y, char op)
{        
    switch(op)
    {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '%': return x % y;
        default: return {};           
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

    std::cout << "Enter the operation (+, -, *, /, %): ";
    char op {};
    std::cin >> op;

    if (const auto result { calculate(x, y, op) })
    {
        std::cout << "x " << op << " y = " << *result << '\n';
    }
    else
    {
        std::cout << "Invalid operation!\n";
    }

    return 0;
}
