#include "ball.h"
#include <iostream>

Ball::Ball(double radius)
{   
    this->color = "black"; 
    this->radius = radius;
}

Ball::Ball(std::string_view color, double radius)
{
    this->color = color;
    this->radius = radius;
}

void Ball::print()
{
    std::cout << "color: " << this->color << ", radius: " << this->radius << "\n";
}
