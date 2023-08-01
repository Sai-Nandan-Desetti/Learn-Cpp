#include "stack.h"
#include <iostream>
#include <cassert>

bool Stack::push(ElementType ele)
{
    if (top + 1 == stackLimit)
    {
        std::cout << "Overflow!\n";
        std::cout << "Cannot insert " << ele << '\n';
        return false;
    }

    array[++top] = ele;

    return true;
}

ElementType Stack::pop()
{
    assert(top != -1 && "Underflow!");

    return array[top--];
}

void Stack::print()
{   
    std::cout << "( ";

    for (int i{0}; i <= top; ++i)
        std::cout << array[i] << ' ';

    std::cout << ")\n";
}

void Stack::reset()
{
    top = -1;
}
