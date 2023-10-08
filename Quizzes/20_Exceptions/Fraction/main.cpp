#include "fraction.h"
#include <iostream>

int main()
{
    std::cout << "Enter a fraction:\n";        
    
    std::cout << "Numerator: ";
    int nr{};
    std::cin >> nr;    
    
    std::cout << "Denominator: ";
    int dr{};
    std::cin >> dr;    
    
    try
    {
        Fraction f{ nr, dr };
        std::cout << "You entered " << f << ".\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
            
    return 0;
}
