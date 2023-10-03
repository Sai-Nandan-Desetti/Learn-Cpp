/**
 * @file main.cpp
 * @author DSN
 * @brief This program sorts a given array using the bubble sort algorithm.
 * @version 0.1
 * @date 2023-07-07
 * 
 */

#include "bubble_sort.h"

int main()
{
    int numbers[]{5, 7, 2, 1, 5, 6, 4};
    std::size_t numbersSize{std::size(numbers)};

    bubbleSort(numbers, 0, numbersSize);
    print(numbers, 0, numbersSize);

    
    char letters[]{'b', 'z', 'e', 'a', 'i', 's', 'n'};
    std::size_t lettersSize{std::size(letters)};

    bubbleSort(letters, 0, lettersSize);
    print(letters, 0, lettersSize);

    
    std::string_view words[]{"word", "four", "serious", "code", "sort", "cult"};
    std::size_t wordsSize{std::size(words)};

    bubbleSort(words, 0, wordsSize);
    print(words, 0, wordsSize);

    return 0;
}
