#include <iostream>

template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y ? y : x);
}

int main()
{
    std::cout << max(4, 6.5) << '\n'; // 6.5
    std::cout << max(6.5, 4) << '\n'; // 6.5

    /* `auto` deduces the return type from the return statement.
    No narrowing conversions possible here.
    */   
    
    return 0;
}
