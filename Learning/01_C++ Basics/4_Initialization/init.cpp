/**
 * @file init.cpp
 * @author DSN
 * @brief Check the output of a variable initialized using zero-initialization.
 * @version 0.3
 * @date 2023-06-27 
 * 
 */

#include <iostream>

int main()
{
    int i{};
    char c{};
    float f{};
    double d{};
    bool b{};

    std::cout << "Output of an integer variable initialized using zero-initialization: " << i << "\n";
    std::cout << "Output of a character variable initialized using zero-initialization: " << c << "\n";
    std::cout << "Output of a float variable initialized using zero-initialization: " << f << "\n";
    std::cout << "Output of a double variable initialized using zero-initialization: " << d << "\n";
    std::cout << "Output of a boolean variable initialized using zero-initialization: " << b << "\n";

    std::cout << "i == 0: " << (i == 0) << "\n";
    std::cout << "c == 0: " << (c == 0) << "\n";
    std::cout << "d == 0: " << (d == 0) << "\n";
    std::cout << "f == 0: " << (f == 0) << "\n";
    std::cout << "b == 0: " << (b == 0) << "\n";
}
