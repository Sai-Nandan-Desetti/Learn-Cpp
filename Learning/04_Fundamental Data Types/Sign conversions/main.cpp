#include <iostream>

int main()
{       
    // unsigned int x{ -1 }; // note: we're using list initialization
    // error: narrowing conversion of '-1' from 'int' to 'unsigned int' [-Wnarrowing]
    
    // unsigned int x = -1; // note: we're using copy initialization
    // warning: unsigned conversion from 'int' to 'unsigned int' changes value from '-1' to '4294967295'
    // If you enable all warnings as errors, then it'd be an error.
    
    constexpr int y{ -1 };
    unsigned int x{ y };
    // error: narrowing conversion of '-1' from 'int' to 'unsigned int' [-Wnarrowing]
    // Since this is an unsafe conversion, it isn't allowed. The following is nevertheless allowed...
    // constexpr int y{ 1 };
    // unsigned int x{ y };
    // ...although y is a signed int
    
    // unsigned int x{};
    // std::cout << "Enter an integer: "; 
    // std::cin >> x;
    std::cout << x << '\n';

    // If you enter -1, no error is thrown
    // x = 4294967295 (probably, system-dependent)
    
    return 0;
}
