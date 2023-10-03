#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	std::string color{ "black" };
	double radius{ 10.0 };

public:
	// // Default constructor with no parameters
	// Ball()
	// {
	// 	this->color = "black";
	// 	this->radius = 10.0;
	// }

	// // Constructor with only color parameter (radius will use default value)
	// Ball(std::string_view color)
	// {
	// 	this->color = color;
	// 	this->radius = 10.0;
	// }

	// Constructor with only radius parameter (color will use default value)
	Ball(double radius) : radius{ radius }    
	{    
	}

	// Constructor with both color and radius parameters
	Ball(std::string_view color = "black", double radius = 10.0)
        : color{ color }, radius{ radius }
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
