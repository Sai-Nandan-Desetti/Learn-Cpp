#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>

/**
 * @brief Sorts T[begin...end) in ascending order by pushing down the heavier elements and bubbling up the lighter ones.
 * @details
 * - At each iteration one element (the heaviest among the unsorted) is in its sorted position.
 *  - So, the outer loop needs to run a maximum of \c length \c - \c 1 times.
 * - If no element was swapped, the array is already sorted.
 * @tparam T
 * @param arr
 * @param begin
 * @param end
 */
template <typename T>
void bubbleSort(T arr[], std::size_t begin, std::size_t end)
{
    std::size_t length{end - begin + 1};
    bool swapped{true};

    for (std::size_t count{0}; swapped and count < length - 1; ++count)
    {
        swapped = false;
        for (std::size_t i{begin + 1}; i < end - count; ++i)
            if (arr[i - 1] > arr[i])
            {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
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
