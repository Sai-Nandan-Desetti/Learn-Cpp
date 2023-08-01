#include <iostream>
#include <string_view>


int main()
{
    constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string target{};
    std::getline(std::cin >> std::ws, target);

    bool isFound{false};
    for (auto& name : names)    
        if (name == target)
        {
            isFound = true;
            break;
        }       
    
    if (isFound)    
        std::cout << target << " was found.\n";    
    else
        std::cout << target << " was not found.\n";

    return 0;
}
