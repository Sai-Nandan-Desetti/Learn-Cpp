#include "io.h"
#include <limits>

std::ostream& operator<<(std::ostream& out, const CardRank& obj)
{
    return out << getName(obj);
}

std::ostream& operator<<(std::ostream& out, const CardSuit& obj)
{
    return out << getName(obj);
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputCleanup()
{
    if (!std::cin)
    {
        if (std::cin.eof())
            exit(0);
        
        std::cin.clear();
        ignoreLine();
    }
    else
        ignoreLine();
}
