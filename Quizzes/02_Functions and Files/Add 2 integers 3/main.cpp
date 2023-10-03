/**
 * @file main.cpp
 * @author DSN
 * @brief Reads two integers from the user and displays their sum.
 * @version 0.1
 * @date 2023-06-28
 * 
 */

/**
 * @mainpage
 * <b>Chapter</b> [2.x](https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/) 
 * \n
 * Modify the program you wrote in #2 so that it uses a header file (named \c io.h)
 * to access the functions instead of using forward declarations directly in your code (.cpp) files.
 *
 */

// include section
// Best practice: include user-defined header files before system-defined ones.
#include "io.h"

// main section
int main()
{
    int x{ readNumber() }, y{ readNumber() };
    writeAnswer(x + y);

    return 0;
}
