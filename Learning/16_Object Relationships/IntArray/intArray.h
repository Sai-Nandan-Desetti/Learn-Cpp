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
#include <cassert>
#include <initializer_list>

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

    bool isValidIndex(std::size_t idx) const;

public:
    /**
     * @brief \c IntArray constructor
     * @details The array is zero-initialized if size is non-zero, else it's null
     * 
     * @param size 
     */
    IntArray(std::size_t size = 0) : m_size{ size },
                                     m_array{ m_size ? new int[m_size]{} : nullptr }
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
     * @brief Construct an \c IntArray from a list of elements
     * @details Delegates the task of allocating space for the array to the constructor that takes only size as input.
     * 
     * @param elements: an initializer list 
     */
    IntArray(std::initializer_list<int> elements) : IntArray(elements.size())
    {        
        std::size_t i{ 0 };
        for (auto ele : elements)
            m_array[i++] = ele;
    }

    std::size_t size() const
    {
        return m_size;
    }

    /**
     * @brief \c IntArray destructor     
     * 
     */
    ~IntArray()
    {
        clear();
        assert (m_array == nullptr and m_size == 0);
    }        

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
     * @brief Allows to set a value at \c m_array[idx]
     * 
     * @param idx: desired index 
     * @return int&: Returns a reference to \c m_array[idx]
     */
    int& at(std::size_t idx);

    /**
     * @brief Ensures that we can only get and not set a value at \c m_array[idx]
     * 
     * @param idx: desired index 
     * @return int: \c m_array[idx] 
     */
    int at(std::size_t idx) const;
    
    /**
     * @brief Erase the contents of the array
     * 
     */
    void clear();

    /**
     * @brief Reallocate space for the array.
     * 
     * @param newSize
     */
    void reallocate(std::size_t newSize);
    
    /**
     * @brief Resize the array-- the previous contents of the array are copied.
     * 
     * @param newSize 
     */
    void resize(std::size_t newSize);

    /**
     * @brief Insert \c value before the given \c index
     * 
     * @param value: the value to be inserted 
     * @param index: after insertion, \c value will be at position \c index, i.e. \c array[index]=value 
     */
    void insertBefore(int value, std::size_t index);

    void insertAtBeginning(int value);

    void insertAtEnd(int value);

    /**
     * @brief Remove the element at the given index.
     * 
     * @param index 
     */
    void remove(std::size_t index);

    /**
     * @brief Swaps two \c IntArrays. Used in \c the definition of \c operator=
     * 
     * @param first 
     * @param second 
     */
    friend void swap(IntArray& first, IntArray& second);

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
