/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-07-03
 *
 */

#include <iostream>
#include <string_view>
#include <iterator>

void fizzbuzz(unsigned int maxNumber)
{
    unsigned int divisors[]{3, 5, 7, 11, 13, 17, 19};
    constexpr int numDivisors{static_cast<int>(std::size(divisors))};

    std::string_view words[]{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

    static_assert(numDivisors == static_cast<int>(std::size(words)));

    bool divisible{false};

    for (unsigned int number{1}; number <= maxNumber; ++number, divisible = false)
    {
        for (unsigned int d{0}; d < numDivisors; ++d)
        {
            if (number % divisors[d] == 0)
            {
                std::cout << words[d];
                divisible = true;
            }
        }

        if (!divisible)
            std::cout << number;

        std::cout << '\n';
    }
}

int main()
{
    std::cout << "Enter the parameter till when you want the game to continue: ";
    unsigned int n{};
    std::cin >> n;

    fizzbuzz(n);

    return 0;
}
