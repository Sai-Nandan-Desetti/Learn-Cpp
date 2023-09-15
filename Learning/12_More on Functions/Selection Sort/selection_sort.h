#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <utility>

template <typename T>
void selectionSort(T* begin, T* end)
{
    for (T* i{begin}; i != (end-1); ++i)
    {
        T* minIndex{i};
        for (T* j{i+1}; j != end; ++j)        
            if(*j < *minIndex)
                minIndex = j;
                     
        if (minIndex != i)
            std::swap(*i, *minIndex);
    }
}

#endif
