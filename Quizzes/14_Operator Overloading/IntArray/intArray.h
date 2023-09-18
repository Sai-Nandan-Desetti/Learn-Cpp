/**
 * @file intArray.h
 * @author DSN
 * @brief Defines the \c IntArray class
 * @version 0.1
 * @date 2023-08-29
 * 
 */

#ifndef INTARRAY_H
#define INTARRAY_H

#include <algorithm> // std::copy
#include <iostream>

/**
 * @brief Simulates an integer array.
 * @details Contains an integer pointer and a parameter to record the size of the array.
 * 
 */
class IntArray
{
private:
    // The order of these attributes is constrained by the order in which we have to perform member-list initialization.
    // Actually, member-list init follows the attribute order, not the other way round.
    // But in this particular example, member-list init must necessarily follow a certain order:
    // namely, that size must be initialized before the array is allocated memory.
    // So, we order the attributes accordingly.
    std::size_t m_size;
    int* m_array;    

public:
    /**
     * @brief \c IntArray constructor
     * @details The array is zero-initialized if size is non-zero, else it's null
     * 
     * @param size 
     */
    IntArray(std::size_t size = 0) : m_size{ size },
                                     m_array{ m_size ? new int[m_size]() : nullptr }
    {
    }

    /**
     * @brief A copy constructor that copies the contents of \c other array into \c this array
     * @details 
     * - The array is default initialized if \c other.m_size is non-zero.
     *  - We do not need to zero-initialize the array because its contents are anyway going to be overwritten immediately.
     * - And the \c this.m_size elements from \c other are copied to \c this.
     *      
     * @param other: another \c IntArray 
     */
    IntArray(const IntArray& other) : m_size{ other.m_size },
                                      m_array{ m_size ? new int[m_size] : nullptr }
    {
        std::copy(other.m_array, other.m_array + m_size, m_array);
    }

    /**
     * @brief \c IntArray destructor
     * @details Free the memory held by the dynamically allocated array member
     * 
     */
    ~IntArray()
    {
        delete[] m_array;
    }

    /**
     * @brief Swaps two \c IntArrays. Used in \c the definition of \c operator=
     * 
     * @param first 
     * @param second 
     */
    friend void swap(IntArray& first, IntArray& second);

    /**
     * @brief Overload the assignment operator to allow array assignments.
     * 
     * @param other: an \c IntArray 
     * @return IntArray& a reference to \c this \c IntArray
     */
    IntArray& operator=(IntArray other);

    /**
     * @brief Provide a standard array-like interface to SET elements of the array.
     * 
     * @param idx: index of the desired element 
     * @return int&: a reference to \c m_array[idx] 
     */
    int& operator[](std::size_t idx);

    /**
     * @brief Provide a standard array-like interface to GET elements of the array.
     * 
     * @param idx: index of the desired element 
     * @return int: \c m_array[idx] 
     */
    int operator[](std::size_t idx) const;

    /**
     * @brief Overload \c operator<< to print an array.
     * 
     * @param out: Generally, \c std::cout 
     * @param arr: reference to a \c const \c IntArray 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);

};

#endif
