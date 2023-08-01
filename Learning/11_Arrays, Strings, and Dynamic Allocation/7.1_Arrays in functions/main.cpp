#include <iostream>

// void byReference(int (&arr)[10])
template <const size_t N>
void byReference(int (&arr)[N])
{
    std::cout << sizeof(arr) << '\n';
}

void byPointer(int array[])
{
    std::cout << sizeof(array) << '\n';
}

int main()
{
    int array[]{5, 6, 3, 6, 7, 3, 6, 7, 8, 3}; // length = 10

    std::cout << sizeof(array) << '\n'; // prints 40

    byReference(array); // prints 40

    byPointer(array); // prints 8

    return 0;
}
