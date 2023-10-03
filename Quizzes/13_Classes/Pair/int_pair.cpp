#include "int_pair.h"
#include <iostream>

IntPair::IntPair() = default;

IntPair::IntPair(int x, int y)
{
    this -> x = x;
    this -> y = y;
}

void IntPair::set(int x, int y)
{
    *this = IntPair(x, y);
}

void IntPair::print()
{
    std::cout << "Pair(" << this -> x << ", " << this -> y << ").\n";
}
