#include <iostream>

int get5()
{
    return 5;
}

int main()
{        
    std::cout << &("Hello") << '\n'; // allowed; C-style string literals are lvalues!        
    
    // std::cout << &(5) << '\n'; // error: lvalue required as unary '&' operand

    // std::cout << &(get5()) << '\n'; // error: lvalue required as unary '&' operand

    return 0;
}
