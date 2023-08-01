#include <iostream>

void printBinary(unsigned short int x)
{
    if (x == 0 || x == 1)
    {
        std::cout << x;
        return;
    }        

    printBinary(x / 2);
    std::cout << x % 2;
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    
    std::cout << "The binary representation of the number:\n";
    printBinary(static_cast<unsigned short int>(x));

    return 0;
}
