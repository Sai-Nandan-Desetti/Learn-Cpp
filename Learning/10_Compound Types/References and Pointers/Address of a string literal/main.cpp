#include <iostream>

int main()
{
    std::cout << &("Hello") << '\n';

    const char* c{ "Hello" };
    std::cout << &c << '\n'; // &c != &("Hello"); `c` is a variable that is itself stored somewhere else (and is only pointing at "Hello" from there)
    std::cout << &(c[0]) << '\n'; // prints "Hello"

    // To get the address of "Hello"
    const char (*d)[]{ &("Hello") }; // d is a pointer to an array of type const char[6] (since "Hello" has 6 elements (including the null character at the end))
    std::cout << d << '\n'; // you get the SAME address as displayed in the the first line of the program;

    return 0;
}
