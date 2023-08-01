#ifndef BALL_H
#define BALL_H

#include <string>
#include <string_view>

class Ball
{
    std::string color{};
    double radius{};

public:    
    Ball(double radius);
    Ball(std::string_view color = "black", double radius = 10.0);
    void print();
};

#endif
