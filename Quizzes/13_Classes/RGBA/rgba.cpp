#include "rgba.h"
#include <iostream>

void RGBA::print()
{
    std::cout << "r=" << static_cast<int>(this->red) << " g=" << static_cast<int>(this->green) << " b=" << static_cast<int>(this->blue) << " a=" << static_cast<int>(this->alpha) << "\n";
}
