/**
 * @file main.cpp
 * @author DSN
 * @brief Print the given triangle
 * @version 0.1
 * @date 2023-07-03
 * 
 */

/**
 * @mainpage
 * Print the following:
    @verbatim
    5 4 3 2 1
    4 3 2 1
    3 2 1
    2 1
    1
    @endverbatim
 * 
 */

#include <iostream>

int main()
{
    constexpr int numRows { 5 };
    int rowStart { numRows };

    while (rowStart > 0)
    {
        int n { rowStart };
        while (n >= 2)
        {
            std::cout << n << ' ';
            n -= 1;
        }
        std::cout << 1 << '\n';

        rowStart -= 1;
    }

    return 0;
}
