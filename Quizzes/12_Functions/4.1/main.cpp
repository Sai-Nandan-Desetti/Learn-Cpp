/**
 * @file main.cpp
 * @author DSN
 * @brief Computes the factorial of the first 50 numbers
 * @details
 *  - <b>Memoize the values</b>:
 *      - Suppose we need to compute \c factorial(8), we've to anyway calculate the factorial of all
 *      integers less than 8 (till 1). So, what's the point of the memoization?
 *      - In this program, we're anyway calculating the \c factorial of the first 50 numbers.
 *      So, before we compute \c \factorial(8), we'd have already computed \c factorial(7).
 *      So, instead of recomputing \c factorial(7), we can directly use the cached value.
 *  - <b>Datatype to be used</b>:
 *      - With std::size_t type, you can represent upto 20! accurately.
 *      - With `double` datatype, I'm not sure of the limit yet.
 * @version 0.1
 * @date 2023-07-11
 * 
 */

#include <cstddef>
#include <vector>
#include <iomanip>
#include <iostream>

#if 0
double factorial (double n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}


double factorial (double n)
{
    static std::vector<double> results{ 1 };
    
    std::size_t _n{ static_cast<std::size_t>(n) };
    
    if (n > 0)
        results.push_back(n * results[_n - 1]);        
        
    return results[_n];
}
#endif

double factorial(double n)
{
    if (n == 0)
    {
        std::cout << "0! = 1\n";
        return 1.0;
    }        
    
    double result{ n * factorial(n - 1) };
    std::cout << n << "! = " << result << '\n';

    return result;
}

int main()
{
    // std::streamsize basePrecision{ std::cout.precision() };

    // std::cout.precision(15); // the precision is sticky...
    std::cout << "The factorial of the first 51 numbers (including 0):\n";

    /*Method 1:
        Calling factorial() in each iteration.
        But caching the results in a static vector so that unnecessary calls aren't made.
    */    
    // for (double i{0}; i <= 50; ++i)
    //      std::cout << i << "! = " << factorial(i) << '\n';    

    /*Method 2:
        Once I did the caching properly, realized that recursion was not required at all.
        Simply accumulate the products.
    */
    // double product{1};
    // for (double i{0}; i <= 50; ++i, product *= i)
    //     std::cout << i << "! = " << product << '\n';
    
    /*Method 3:
        Can you use recursion but ensure that for any n, factorial(n) is called only once?
    */
    factorial(50);

    // std::cout.precision(basePrecision); // ...reset to default value
    // std::cout << 3.141567165498 << '\n';    

    return 0; 
}
