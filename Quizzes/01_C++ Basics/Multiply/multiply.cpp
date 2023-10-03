/**
 * @file multiply.cpp
 * @author DSN
 * @brief Multiply a given number (double and triple)
 * 
 * Quiz question 1 in [lesson 1.11](https://www.learncpp.com/cpp-tutorial/developing-your-first-program/)
 * 
 * @version 0.1
 * @date 2023-06-27
 * 
 */

#include <iostream>

int main()
{
    int num{};

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "Double: " << num * 2 << "\n";
    std::cout << "Triple: " << num * 3 << "\n";
}
