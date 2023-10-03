/**
 * @file main.cpp
 * @author DSN
 * @brief Reads two integers from the user and displays their sum.
 * @version 0.2
 * @date 2023-06-28
 * 
 */

/**
 * @mainpage
 * <b>Chapter</b> [2.x](https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/) 
 * \n
 * Modify the program you wrote in exercise #1 so that \c readNumber() and \c writeAnswer()
 * live in a separate file called \c io.cpp.
 * Use a forward declaration to access them from \c main().
 * 
 */

// function prototypes

/**
 * @brief Reads an integer from the user.
 * 
 */
int readNumber();

/**
 * @brief Displays an integer in the terminal.
 *  
 */
void writeAnswer(int output);


// main section
int main()
{
    int x{ readNumber() }, y{ readNumber() };
    writeAnswer(x + y);

    return 0;
}
