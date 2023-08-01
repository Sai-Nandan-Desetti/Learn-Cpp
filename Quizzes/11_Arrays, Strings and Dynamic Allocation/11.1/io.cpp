#include <iostream>
#include <string>

void getNames(std::string* names, std::size_t numberOfNames)
{
    for (std::size_t i{0}; i < numberOfNames; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
}

void print(std::string* names, std::size_t numberOfNames)
{
    for (std::size_t i{0}; i < numberOfNames; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}
