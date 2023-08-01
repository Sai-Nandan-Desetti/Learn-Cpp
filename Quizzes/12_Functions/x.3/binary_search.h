#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iterator>

template <typename Iterator, typename ElementType>
Iterator binarySearch(Iterator begin, Iterator end, const ElementType target)
{   
    Iterator left{ begin };
    Iterator right{ end }; 
    Iterator mid{};

    while (left < right)
    {
        mid = left + std::distance(left, right) / 2;

        if (*mid == target)
            return mid;
        else
        {
            if (*mid < target)
                left = mid + 1;
            else
                right = mid;
        }                    
    }

    return end;
}

#endif
