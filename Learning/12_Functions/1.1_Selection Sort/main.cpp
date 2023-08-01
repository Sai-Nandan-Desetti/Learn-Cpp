#include "selection_sort.h"
#include "io.h"

int main()
{
    int numbers[]{5, 7, 2, 1, 5, 6, 4};
    std::size_t numbersSize{std::size(numbers)};

    selectionSort(numbers, numbers + numbersSize);
    print(numbers, numbers + numbersSize);


    char letters[]{'b', 'z', 'e', 'a', 'i', 's', 'n'};
    std::size_t lettersSize{std::size(letters)};

    selectionSort(letters, letters + lettersSize);
    print(letters, letters + lettersSize);

    
    std::string_view words[]{"word", "four", "serious", "code", "sort", "cult"};
    std::size_t wordsSize{std::size(words)};

    selectionSort(words, words + wordsSize);
    print(words, words + wordsSize);

    return 0;
}
