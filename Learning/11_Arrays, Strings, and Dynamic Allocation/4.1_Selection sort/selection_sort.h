#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>

#if 0
template <typename T, const std::size_t N>
void selectionSort(T (&array)[N])
{
    for (std::size_t i{0}; i < N - 1; ++i)
    {
        std::size_t minIndex {i};
        for (std::size_t j{i + 1}; j < N; ++j)
            if (array[j] < array[minIndex])
                minIndex = j;

        if (minIndex != i)
            std::swap(array[i], array[minIndex]);
    }
}

/* Not necessary to define a template for the size as well */
template <typename T>
void selectionSort(T& arr)
{
    std::size_t size = std::size(arr);

    for (std::size_t i = 0; i < size - 1; ++i)
    {
        std::size_t minIndex = i;
        for (std::size_t j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

template <typename T, const std::size_t N>
void print(const T (&array)[N])
{
    for (std::size_t i{0}; i < N; ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';
}
#endif

/**
 * @brief Sorts \c T[begin...end) in ascending order by fixing the position of the minimum element among the unsorted.
 * @details
 * - After each iteration of the outer loop, \c array[begin...index] is sorted.
 * - After each iteration of the inner loop, \c min(arr[index+1...end)) is swapped with \c arr[index].
 * @tparam T: could be \c int, \c char, \c string 
 * @param array: an array of elements where each element if of type \c T 
 * @param begin: \c begin = 0, if you want to sort the entire array 
 * @param end: \c end = len(array), if you want to sort the entire array 
 */
template <typename T>
void selectionSort(T array[], std::size_t begin, std::size_t end)
{
    for (std::size_t index{begin}; index < end - 1; ++index)
    {
        std::size_t minIndex = index;
        for (std::size_t j = index + 1; j < end; ++j)    
            if (array[j] < array[minIndex])            
                minIndex = j;

        if (minIndex != index)
            std::swap(array[index], array[minIndex]);        
    }
}

template <typename T>
void print(const T array[], std::size_t begin, std::size_t end)
{
    for (std::size_t index{begin}; index < end; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';
}

#endif
