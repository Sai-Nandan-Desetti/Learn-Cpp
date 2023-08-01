#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";

	// Allow the user to enter 'true' or 'false' for boolean values
	// This is case-sensitive, so True or TRUE will not work
    // (Try entering 1 and see what you get as the output.)	
	std::cin >> std::boolalpha >> b;
    std::cout << "You entered: " << b << '\n';

	return 0;
}
