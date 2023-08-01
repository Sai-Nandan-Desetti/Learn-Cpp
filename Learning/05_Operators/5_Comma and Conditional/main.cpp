#include <iostream>

int main()
{
    (std::cout << (2 > 3)) ? 2 : 3 << '\n';
    //error: second operand of conditional expression has no effect
}
