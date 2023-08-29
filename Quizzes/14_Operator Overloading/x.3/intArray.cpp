/**
 * @file intArray.cpp
 * @author DSN
 * @brief Defines functions related to \c IntArray
 * @version 0.1
 * @date 2023-08-29
 * 
 */

#include "intArray.h"
#include <cassert>


/**
 * @details Uses \c std::swap to swap the members.
 * - We efficiently swap only the array pointers of the two \c IntArrays
 * 
 */
void swap(IntArray& first, IntArray& second)
{    
    std::swap(first.m_size, second.m_size);
    std::swap(first.m_array, second.m_array);
}

/**
 * @details There are several things to note:
 * - \c other is passed by value.
 *  - This ensures that a copy constructor is invoked by the compiler.
 *  - If, for some reason, the copy fails, control never enters the funtion body; therefore, \c this isn't modified.
 * - We swap \c *this and \c other. This has the following benefits
 *  - We don't need to explicitly handle self-assignment.
 *  - \c swap is atomic.
 *  - Because a copy is already created, we do not need to re-copy the entire contents of the arrays.
 *  - We've elegantly avoided duplicating the code of the copy constructor.
 * - After the swap, \c other points to the old content of \c *this. Once the control exits the function, the destructor of \c other is called.
 * And it, thereby, deletes (i.e. invokes \c delete[] for) the array that was previously a member of \c *this.
 *  - Thus, we've avoided duplicating the code for the destructor as well!
 * 
 * - Ref: \ref [What is the copy-and-swap idiom?](https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom#3279550)
 */
IntArray& IntArray::operator=(IntArray other)
{
    swap(*this, other);
    
    return *this;
}

/**
 * @details
 * @code {.cpp}
 * IntArray a{ 2 };
 * a[0] = 1;
 * a[1] = 2;
 * @endcode
 * This is a case where \c a[i] needs to be SET.
 * 
 */
int& IntArray::operator[](std::size_t idx)
{
    assert (idx < m_size);
    
    return m_array[idx];
}

/**
 * @details
 * @code {.cpp}
 * IntArray a{ 2 };
 * std::cout << a[1];
 * @endcode
 * This is an example where you only need to get \c a[i].
 * Its value mustn't be modified. Hence the \c const specifier.
 * 
 */
int IntArray::operator[](std::size_t idx) const
{
    assert (idx < m_size);
    
    return m_array[idx];
}

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
    for (std::size_t i{ 0 }; i < arr.m_size; ++i)
        out << arr[i] << ' ';

    return out;
}
