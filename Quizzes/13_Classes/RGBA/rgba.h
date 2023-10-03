#ifndef RGBA_H
#define RGBA_H

#include <cstdint> // for std::uint8_t

class RGBA
{
public:
    using Channel = std::uint8_t;

private:
    Channel red{};
    Channel green{};
    Channel blue{};
    Channel alpha{};

public:
    RGBA(Channel r = 0, Channel g = 0, Channel b = 0, Channel a = 255)
        : red{r}, green{g}, blue{b}, alpha{a}
    {        
    }    
    void print();
};

#endif
