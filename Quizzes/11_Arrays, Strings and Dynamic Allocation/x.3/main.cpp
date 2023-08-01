#include <iostream>

void swap(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    std::cout << "Enter x: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter y: ";
    int y{};
    std::cin >> y;

    swap(x, y);

    std::cout << "\nAfter swapping\n";
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    return 0;
}
