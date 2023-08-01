#ifndef STACK_H
#define STACK_H

#include <cstddef>

constexpr std::size_t stackLimit{3};
typedef int ElementType;

class Stack
{
private:
    ElementType array[stackLimit]{};
    int top{-1};

public:
    bool push(ElementType ele);
    ElementType pop();
    void print();
    void reset();
};

#endif
