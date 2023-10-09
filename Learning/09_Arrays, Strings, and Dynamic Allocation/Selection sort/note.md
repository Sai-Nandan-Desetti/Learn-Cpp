At this point I think it's useful to challenge yourself to write a function `selectionSort()` that takes only an `array` (without its size) as an argument.

You can first write it for integer arrays only.

Then, increase the challenge to write a template function that can sort arrays of integers, characters, and strings, respectively.
Also, write a template function that prints an array.

**selection_sort.h**
```
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>

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


template <typename T, const std::size_t N>
void print(const T (&array)[N])
{    
    for (std::size_t i{0}; i < N; ++i)    
        std::cout << array[i] << ' ';

    std::cout << '\n';
}

#endif

```

**main.cpp**
```
#include "selection_sort.h"

int main()
{
    int numbers[]{5, 7, 2, 1, 5, 6, 4};
    selectionSort(numbers);
    print(numbers);

    char letters[]{'b', 'z', 'e', 'a', 'i', 's', 'n'};
    selectionSort(letters);
    print(letters);

    std::string_view words[]{"word", "four", "serious", "code", "sort", "cult"};
    selectionSort(words);
    print(words);

    return 0;
}
```

**Do you see what's the issue with this?**
Each time you define an array of a different size (even if same type), a different function has to be defined! The way to resolve this is to separate the template function parameter from the array size. Keep the template parameter only for the data type, not the size.

So, can we do the following?
```
void selectionSort(T& arr)
{
    std::size_t size = std::size(arr);

    for (std::size_t i = 0; i < size - 1; ++i)
    {
        std::size_t minIndex = i;
        for (std::size_t j = i + 1; j < size; ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        if (minIndex != i)
            std::swap(arr[i], arr[minIndex]);
    }
}
```

Nope. When `selectionSort(numbers)` is called, for example, `T` is deduced to be `int [7]`. So, when you call `selectionSort()` on an integer array of a different size, a different function gets defined again!

You want different functions only for different data types and not different sizes. One way to ensure this is to simply pass `size` as a separate argument:
```
template<typename T>
void selectionSort(T arr[], std::size_t size)
{
    for (std::size_t i = 0; i < size - 1; ++i)
    {
        std::size_t minIndex = i;
        for (std::size_t j = i + 1; j < size; ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        if (minIndex != i)
            std::swap(arr[i], arr[minIndex]);
    }
}
```

Note that size has no connection with the template stuff.
