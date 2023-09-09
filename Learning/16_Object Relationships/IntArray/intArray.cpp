/**
 * @file intArray.cpp
 * @author DSN
 * @brief Defines functions related to \c IntArray
 * @version 0.1
 * @date 2023-08-29
 * 
 */

#include "intArray.h"
#include <stdexcept>


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

bool IntArray::isValidIndex(std::size_t index) const
{
    return index < m_size;
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
    assert (isValidIndex(idx));
    
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
    assert (isValidIndex(idx));
    
    return m_array[idx];
}

int& IntArray::at(std::size_t idx)
{
    if (!isValidIndex(idx))
        throw std::out_of_range("Index out of range!");

    return (*this)[idx];
}

int IntArray::at(std::size_t idx) const
{
    if (!isValidIndex(idx))
        throw std::out_of_range("Index out of range!");

    return (*this)[idx];
}

/**
 * @details 
 * - The array pointer must be set to null; else it'd be pointing to deallocated memory.
 * - The size too must be set to zero.
 * 
 */
void IntArray::clear()
{
    delete[] m_array;
    m_array = nullptr;
    m_size = 0;
}

/**
 * @details The previous contents of the array are deleted. 
 * - I don't think we need this method. 
 */
void IntArray::reallocate(std::size_t newSize)
{    
    *this = IntArray(newSize);
}

/**
 * @details
 * - If the \c newSize is the same as the old one, then don't change anything.
 * - Else, 
 *  - Create a new array with size = new size.
 *  - Copy as many as elements as possible (the minimum of the two sizes) from the old array to the new one.
 *  - Use the overloaded assignment operator to assign the new one back to the old one.
 * 
 */
void IntArray::resize(std::size_t newSize)
{   
    if (newSize == m_size)
        return;
    
    IntArray arr(newSize);
    for (std::size_t i{ 0 }; i < std::min(m_size, newSize); ++i)
        arr[i] = (*this)[i];

    *this = arr;
}

/**
 * @details
 * - Create a temporary array of size: old size + 1.
 * @code {.cpp}
 * arr[k] = (*this)[k], k < index
 * arr[index] = (*this)[index]
 * arr[k] = (*this)[k - 1], k > index
 * @endcode
 * - Assign \c arr back to \c *this
 * 
 */
void IntArray::insertBefore(int value, std::size_t index)
{
    assert (isValidIndex(index) or index == m_size);

    IntArray arr(m_size + 1);

    for (std::size_t i{ 0 }; i < index; ++i)
        arr[i] = (*this)[i];
    
    arr[index] = value;

    for (std::size_t i{ index + 1 }; i < arr.size(); ++i)
        arr[i] = (*this)[i - 1];

    *this = arr;
}

void IntArray::insertAtBeginning(int value)
{
    insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
    insertBefore(value, m_size);
}

/**
 * @details
 * - Create a temporary array of size: old size - 1
 * @code {.cpp}
 * arr[k] = (*this)[k], k < index
 * arr[k] = (*this)[k + 1], k >= index
 * @endcode
 * - Assign \c arr back to \c *this
 * 
 */
void IntArray::remove(std::size_t index)
{
    assert (isValidIndex(index));

    IntArray arr(m_size - 1);
    
    for (std::size_t i{ 0 }; i < index; ++i)
        arr[i] = (*this)[i];

    for (std::size_t i{ index }; i < arr.size(); ++i)
        arr[i] = (*this)[i + 1];

    *this = arr;
}

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

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
    for (std::size_t i{ 0 }; i < arr.size(); ++i)
        out << arr[i] << ' ';

    return out;
}
