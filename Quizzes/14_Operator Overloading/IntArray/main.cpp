/**
 * @file main.cpp
 * @author DSN
 * @brief A demonstration of \c IntArray
 * @version 0.1
 * @date 2023-08-29
 * 
 */

/**
 * @mainpage
 * Using the pretext of implementing a rudimentary integer array from scratch,
 * we learn several important concepts pertaining to resource management of dynamically allocated memory.
 * It's necessary that you define the following four:
 * - Constructor
 * - Copy constructor
 * - Overloading assignment operator
 * - Destructor
 * 
 */

#include "intArray.h"

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}


int main()
{
	IntArray a{ fillArray() };

    std::cout << "Array a:\n";
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
    std::cout << "\nb = a (Deep copy):\n";
	b = a;
	std::cout << b << '\n';

    std::cout << "\na[4] = 7\n";
    a[4] = 7;
    
    std::cout << "\nModified array a:\n" << a << '\n';
    std::cout << "Unaffected array b:\n" << b << '\n';

	return 0;
}
