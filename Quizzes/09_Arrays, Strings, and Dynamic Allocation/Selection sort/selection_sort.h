#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>

/**
 * @brief Sorts T[begin...end) in descending order.
 * 
 * @tparam T 
 * @param arr 
 * @param begin 
 * @param end 
 */
template <typename T>
void selectionSort(T arr[], std::size_t begin, std::size_t end)
{
    for (std::size_t i{begin}; i < end - 1; ++i)
    {   
        std::size_t maxIndex{i};
        for (std::size_t j{i + 1}; j < end; ++j)
            if (arr[j] > arr[maxIndex])
                maxIndex = j;

        if (maxIndex != i)
            std::swap(arr[i], arr[maxIndex]);
    }
}

template <typename T>
void print(T arr[], std::size_t begin, std::size_t end)
{
    for (std::size_t index{begin}; index < end; ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';
}

#endif
