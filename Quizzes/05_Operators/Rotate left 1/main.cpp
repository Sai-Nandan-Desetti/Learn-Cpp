/**
 * @file main.cpp
 * @author DSN
 * @brief Left-rotate a given set of bits
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
 *  - It’s okay to use \c test() and \c set() included in the \c bitset header file.
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
 * @brief Left rotate a set of bits.
 * @details
 * - Test the left-most bit
 * - Shift left by 1 bit
 * - Set the right-most bit to the left-most bit (if it is set)
 * \n
 * (<b>IMPORTANT</b>: We count from right to left; starting from 0.)
 * @param bits 
 * @return \c bits rotated left. 
 */
std::bitset<NUM_BITS> rotl(std::bitset<NUM_BITS> bits)
{
    const bool leftMostbit{ bits.test(NUM_BITS - 1) };
    
    bits <<= 1;
    
    if (leftMostbit)        
        bits.set(0, leftMostbit);

    return bits;    
}


int main()
{
    std::bitset<NUM_BITS> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

	std::bitset<NUM_BITS> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
