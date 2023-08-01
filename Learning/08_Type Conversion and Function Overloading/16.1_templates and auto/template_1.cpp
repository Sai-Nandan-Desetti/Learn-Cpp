#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y ? y : x);
}

int main()
{
    std::cout << max(3, 7) << '\n';
    
    /*
    std::cout << max(3, 5.6) << '\n';
    
    Compile error: No matching function found.
    The template expects both arguments to be of same type.
    
    You might wonder why the compiler didn’t generate function max<double>(double, double)
    and then use numeric conversion to type convert the int argument to a double.
    The answer is simple:
    Type conversion is done only when resolving function overloads,
    not when performing template argument deduction.
    */

    return 0;
}
