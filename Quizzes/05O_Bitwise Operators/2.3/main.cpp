/**
 * @file main.cpp
 * @author DSN
 * @brief Left-rotate a given bitset
 * @version 0.1
 * @date 2023-07-01
 * 
 */

/**
 * @mainpage
 * \n
 * <b>Chapter</b> [O.2](https://www.learncpp.com/cpp-tutorial/bitwise-operators/)
 * \n
 * A bitwise rotation is like a bitwise shift,
 * except that any bits shifted off one end are added back to the other end.
 * For example \c 0b1001u \c << \c 1 would be \c 0b0010u, but a left rotate by \c 1 would result in \c 0b0011u instead.
 *  - Implement a function that does a left rotate on a \c std::bitset<NUM_BITS>.
 *  - DO NOT use \c test() and \c set() included in the \c bitset header file.
 *  - Use bitwise operators.
 */


#include <bitset>
#include <iostream>


/**
 * @brief Number of bits comprising a \c bitset.
 * @details
 * Why don't we use @verbatim #define NUM_BITS 4 @endverbatim
 * Using \c #define, \c NUM_BITS doesn't become a variable.
 * So, you can't watch it in a debugger.
 * In VS Code you can simply hover the cursor over `NUM_BITS` to see its value.
 * But where you don't have such a luxury you'll have to observe its value using a debugger.
 * So, best to declare it as compile-time constant using \c constexpr.
 */
constexpr unsigned int NUM_BITS{ 4u };


/**
 * @brief Left rotate a bitset.
 * @details
 * Left shit \c bits by 1 and \c bitwise-OR it with \c bits right-shifted till (excluding) the last bit.
 * \n
 * @param bits 
 * @return \c bits rotated left. 
 */
std::bitset<NUM_BITS> rotl(std::bitset<NUM_BITS> bits)
{   
    return (bits << 1) | (bits >> (NUM_BITS - 1));    
}


int main()
{
    std::bitset<NUM_BITS> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

	std::bitset<NUM_BITS> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
