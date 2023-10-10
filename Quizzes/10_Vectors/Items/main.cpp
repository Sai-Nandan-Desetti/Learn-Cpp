#include <vector>
#include <cassert>
#include <numeric> // std::reduce
#include <string_view>
#include <iostream>

namespace Items
{
    enum Type
    {
        potion,
        torch,
        arrow,
        max_items
    };
}

std::string_view getSingularName(Items::Type type)
{            
    switch (type)
    {
    case Items::potion:
        return "potion";
    case Items::torch:
        return "torch";
    case Items::arrow:
        return "arrow";

    default:
        return "???";
    }
}

std::string_view getPluralName(Items::Type type)
{
    switch (type)
    {
    case Items::potion:
        return "potions";
    case Items::torch:
        return "torches";
    case Items::arrow:
        return "arrows";

    default:
        return "???";
    }
}

using Size = std::size_t;
using Inventory = std::vector<Size>;

void print(const Inventory& inventory, Items::Type type)
{
    bool plural{ inventory[type] != 1 };
    std::cout << "You have " << inventory[type] << ' ' << (plural ? getPluralName(type) : getSingularName(type)) << ".\n";
}

int main()
{
    Inventory inventory{ 1, 5, 10 };
    
    assert(inventory.size() == Items::max_items);

    // std::cout << "You have " << std::reduce(inventory.begin(), inventory.end()) << " total items.\n";

    Size sum{ 0 };
    for (Size i{}; i < Items::max_items; ++i)
    {
        sum += inventory[i];
        print(inventory, static_cast<Items::Type>(i));        
    }
    
    std::cout << "You have a total of " << sum << " items.\n";

    return 0;
}
