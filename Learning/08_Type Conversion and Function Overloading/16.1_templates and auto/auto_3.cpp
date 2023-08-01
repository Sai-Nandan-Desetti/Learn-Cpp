#include <iostream>

auto max(auto x, auto y)
{
    return (x < y ? y : x);
}

auto min(auto x, auto y)
{
    return (x < y ? x : y);
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << max(x, y) << " >= " << min(x, y) << '\n';    
    
    return 0;
}
