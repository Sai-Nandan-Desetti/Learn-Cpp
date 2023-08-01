/**
 * @file main.cpp
 * @author DSN
 * @brief Adds two numbers input by the user. 
 * @version 0.1
 * @date 2023-06-27
 * 
 */


/**
 * @mainpage
 * This is the first program in C++ where I'm using multiple files.
 * \n I'm also using this to test how documentation works for multiple files.
 */


// include section
#include <iostream>

// prototype section
int getInteger();


// main section
int main()
{
    int x{ getInteger() };
    int y{ getInteger() };

    std::cout << x << " + " << y << " = " << x + y << "\n";

    return 0;
}
