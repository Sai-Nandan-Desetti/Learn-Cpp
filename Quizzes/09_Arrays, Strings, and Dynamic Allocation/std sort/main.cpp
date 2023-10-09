#include "io.h"
#include <iostream>
#include <algorithm>

int main()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t numberOfNames{};
    std::cin >> numberOfNames;

    std::string* names{ new std::string[numberOfNames]{} };
    getNames(names, numberOfNames);

    std::sort(names, names + numberOfNames);

    std::cout << "\nHere is your sorted list:\n";
    print(names, numberOfNames);

    delete[] names;
    
    return 0;
}
