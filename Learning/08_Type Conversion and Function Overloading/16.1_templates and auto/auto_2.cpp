#include <iostream>

auto max(auto x, auto y)
{
    return (x < y ? y : x);
}

int main()
{
    std::cout << max(4, 6.5) << '\n'; // 6.5
    std::cout << max(6.5, 4) << '\n'; // 6.5

    /* Why not use auto to automatically deduce the parameter types as well? */   
    
    return 0;
}
