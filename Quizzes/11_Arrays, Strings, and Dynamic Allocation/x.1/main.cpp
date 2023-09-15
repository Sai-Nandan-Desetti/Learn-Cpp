#include <iostream>
#include <array>
#include <numeric>

enum Items
{
    health_potions,
    torches,
    arrows,
    max_items
};

using Inventory = std::array<int, Items::max_items>;

int countTotalItems(const Inventory& items)
{
    return std::reduce(items.begin(), items.end());
}

int main()
{
    Inventory myItems{2, 5, 10};
    std::cout << "Total items: " << countTotalItems(myItems) << '\n';
    std::cout << "Number of torches: " << myItems[Items::torches] << '\n';

    return 0;
}
