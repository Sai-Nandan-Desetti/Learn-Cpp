#include "operator.h"
#include "operation.h"
#include "io.h"

int main()
{
    std::cout << "Enter an integer: ";    
    int x{ getInteger() };    

    std::cout << "Enter another intger: ";    
    int y{ getInteger() };

    Operator op{};
    do
    {
        std::cout << "What operation would you like to perform?\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        
        std::cout << "\nOption (You can enter the option number or the operator symbol): ";
        std::cin >> op;
        inputCleanup();

    } while (not isValid(op));

    ArithmeticFunction operation{ getArithmeticFunction(op) };

    if (operation)
        std::cout << x << ' ' << op << ' ' << y << " = " << operation(x, y) << '\n';
            
    return 0;
}
