#include "binary_search.h"
#include <array>
#include <iostream>

int main()
{
    constexpr std::array array{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr std::size_t numTestValues{ 9 };

    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };      

    // And here are the expected results for each value
    constexpr int expectedValues[numTestValues]{ array.size(), 0, 3, array.size(), array.size(), 8, array.size(), 13, array.size() };

    // Loop through all of the test values
    for (std::size_t count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        auto index{ binarySearch(array.begin(), array.end(), testValues[count]) };
        // If it matches our expected value, then great!
        if (std::distance(array.begin(), index) == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}
