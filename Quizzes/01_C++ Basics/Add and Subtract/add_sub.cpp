/**
 * @file add_sub.cpp
 * @author DSN
 * @brief Add and subtract two numbers
 * @details Quiz question 3 in summary of chapter 1, [1.x](https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz/).
 * @version 0.4
 * @date 2023-06-27
 * 
 */

#include <iostream>

int main() {

    int x{}, y{};

    std::cout << "Enter a number: ";
    std::cin >> x;

    std::cout << "Enter another number: ";
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y <<".\n";
    std::cout << x <<" - " << y << " is " << x - y << ".\n";

    return 0;
}
