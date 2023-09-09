#include <iostream>
#include "intArray.h"

int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (std::size_t i{ 0 }; i < 10; ++i)
        array[i] = static_cast<int>(i) + 1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element at index 5
    array.insertBefore(20, 5);

    // Remove the element at index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
    {
        IntArray b{ array };
        b = array;
        b = b;
        array = array;
    }

    // Print out all the numbers
    for (std::size_t i{ 0 }; i < array.size(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    IntArray list{ 5, 4, 3, 2, 1 }; // initializer list
	for (std::size_t count{ 0 }; count < list.size(); ++count)
		std::cout << list[count] << ' ';

    std::cout << '\n';

	list = { 1, 3, 5, 7, 9, 11 };
	for (std::size_t count{ 0 }; count < list.size(); ++count)
		std::cout << list[count] << ' ';

	std::cout << '\n';

    return 0;
}
