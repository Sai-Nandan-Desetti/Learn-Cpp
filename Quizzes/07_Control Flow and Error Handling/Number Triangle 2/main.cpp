/**
 * @file main.cpp
 * @author DSN
 * @brief Print the given triangle
 * @version 0.3
 * @date 2023-07-03
 * 
 */

/**
 * @mainpage
 * Print the following:
    @verbatim
            1
          2 1
        3 2 1
      4 3 2 1
    5 4 3 2 1
    @endverbatim
 */


#include <iostream>

/* Version 0.2:
    - Row x: Print (5-x)*2 spaces. Then, print from x till 1.
 */
#if 0
int main()
{
    constexpr int numRows { 5 };
    int rowStart { 1 };

    while (rowStart <= numRows)
    {
        // print spaces
        int numSpaces { (numRows - rowStart)*2 };
        int spaces { 0 };
        while (spaces < numSpaces)
        {
            std::cout << ' ';
            spaces += 1;
        }
        
        // print numbers
        int number { rowStart };
        while (number > 1)
        {
            std::cout << number << ' ';
            number -= 1;
        }
        std::cout << 1 << '\n';

        ++rowStart;
    }
}
#endif


/* Version 0.3 
    - Row x:
        - n goes from 5 to 1.
        - Print n if n <= x
        - Else, print ' '
*/
int main()
{
    constexpr int numRows { 5 };
    int rowNum { 1 };

    while (rowNum <= numRows)
    {
        int n { numRows };
        while (n >= 2)
        {
            if (n <= rowNum)
                std::cout << n;
            else
                std::cout << ' ';
            
            std::cout << ' ';            
            --n;
        }
        std::cout << 1 << '\n';

        ++rowNum;
    }

    return 0;
}
