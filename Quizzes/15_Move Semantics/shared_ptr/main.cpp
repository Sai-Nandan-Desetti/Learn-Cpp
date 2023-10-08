#include <iostream>
#include <memory> // std::make_shared

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto res{ std::make_shared<Resource>() };
	auto ptr1{ res };
	auto ptr2{ ptr1 };

	return 0;
}
