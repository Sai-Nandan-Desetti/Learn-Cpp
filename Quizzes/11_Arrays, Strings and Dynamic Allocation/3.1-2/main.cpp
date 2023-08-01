#include "io.h"
#include <iostream>
#include <iterator>

int getPos(const int array[], int length, int ele);
void print(const int array[], int length);


int main()
{
    constexpr int array[] { 4, 6, 7, 3, 8, 2, 1, 9, 5 };    
    constexpr int length { static_cast<int>(std::size(array)) };

    int input {};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> input;
        inputCleanup();

    } while (input < 1 or input > 9);
    
    print(array, length);
    
    int position { getPos(array, length, input) };
    if (position != -1)
        std::cout << "The number " << input << " has index " << position <<".\n";
    
    return 0;
}


int getPos(const int array[], int length, int ele)
{
    for (int index {0}; index < length; ++index)
    {
        if (array[index] == ele)        
            return index;        
    }
    return -1;
}

void print(const int array[], int length)
{
    int index {0};
    for (; index < length - 1; ++index)
        std::cout << array[index] << ' ';

    std::cout << array[index] << '\n';
}
