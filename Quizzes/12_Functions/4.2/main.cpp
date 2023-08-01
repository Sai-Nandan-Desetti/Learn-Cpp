#include <iostream>

int getSumOfDigits(int number)
{   
    if (number >= 0 and number <= 9)
        return number;

    return (number % 10) + getSumOfDigits(number / 10);
}

int main()
{
    std::cout << "Enter an integer: ";
    int number{};
    std::cin >> number;
    
    std::cout << "The sum of the digits of " << number << " = " << getSumOfDigits(number) << '\n';

    return 0;
}
