#include <iostream>
#include <vector>

void printInt(int x)
{
    std::cout << x << '\n';
}

// void printInt(char) = delete; // calls to this function will halt compilation
// void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(5);   // okay
    printInt('a');  // compile error
    printInt(true); // compile error

    return 0;
}
