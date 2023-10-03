/**
 * @file main.cpp
 * @author DSN
 * @brief Get the name and age of a user and return the sum of the age and the length of the name.
 * @details This program is to familiarize oneself with the basics of strings.
 * @version 0.1
 * @date 2023-06-29
 *
 */

/**
 * @mainpage
 * <b>Chapter</b> [4.17](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/)
 * \n
 * Write a program that asks the user to enter their full name and their age.
 * As output, tell the user the sum of their age and the number of letters in their name
 * (use the \c std::string::length() member function to get the length of the string).
 * For simplicity, count any spaces in the name as a letter.
 * \n
 * Sample output:
    @verbatim
    Enter your full name: John Doe
    Enter your age: 32
    Your age + length of name is: 40
    @endverbatim
 */

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    std::cout << "Your age + length of name is: " << age + std::ssize(name) << std::endl;
    // std::cout << "Your age + length of name is: " << age + static_cast<int>(name.length()) << std::endl;
}
