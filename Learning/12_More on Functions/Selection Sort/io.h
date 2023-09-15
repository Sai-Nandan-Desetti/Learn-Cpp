#ifndef IO_H
#define IO_H

#include <iostream>

template <typename T>
void print(T* begin, T* end)
{
    for (T* it{begin}; it != end; ++it)
        std::cout << *it << '\t';

    std::cout << '\n';
}

#endif
