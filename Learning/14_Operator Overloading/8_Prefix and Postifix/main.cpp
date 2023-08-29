#include "digit.h"


int main()
{
    Digit d{ -1 };

    /* Display the digits as a palindrome using prefix operators */
    #if 0
    std::cout << d << ' ';
    while (d < 9)
        std::cout << ++d << ' ';
    
    while (d > 0)
        std::cout << --d << ' ';
    std::cout << '\n';
    #endif

    /* Display the digits as a palindrome using postfix operators */
    #if 0    
    while (d < 9)
        std::cout << d++ << ' ';    
    std::cout << d-- << ' ';
    
    while (d > 0)
        std::cout << d-- << ' ';
    std::cout << d << '\n';
    #endif
        
    std::cout << "d: " << d << '\n';
    std::cout << "++d-- = " << ++d-- << '\n';
    std::cout << "d: " << d << '\n';
    
    return 0;
}
