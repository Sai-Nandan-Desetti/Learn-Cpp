#include <iostream>

template <typename T, typename U>
T mult(T x, U y)
{
    return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
