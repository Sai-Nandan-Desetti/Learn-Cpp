#include <iostream>

template <typename T, typename U>
T max(T x, U y)
{
    return (x < y ? y : x);
}

int main()
{
    std::cout << max(4, 6.5) << '\n'; // 6
    std::cout << max(6.5, 4) << '\n'; // 6.5

    /* Crazy! 
    Two functions are actually defined. Hover cursor over max() in main().
    This kind of template definition allows for narrowing conversion.
    */
    
    return 0;
}
