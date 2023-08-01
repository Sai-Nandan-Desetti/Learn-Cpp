#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	std::string color{};
	double radius{};

public:	
    // Constructor with both color and radius parameters
	Ball(std::string_view color = "black", double radius = 10.0)
        : color{ color }, radius{ radius }
	{		
	}

	// Constructor with only radius parameter
    // Delegate to the constructor that takes both parameters
	Ball(double radius) : Ball("black", radius)
	{    
	}	

	void print()
	{
		std::cout << "color: " << color << ", radius: " << radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}
