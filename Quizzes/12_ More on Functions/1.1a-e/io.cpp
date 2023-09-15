#include "io.h"
#include <limits>

std::istream& operator>>(std::istream& in, Operator& op)
{
    char input{};
    in >> input;

    op = getOperator(input);
    
    return in;
}

std::ostream& operator<<(std::ostream& out, Operator op)
{
    return out << getName(op);    
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


int getInteger()
{
    int input{};
    std::cin >> input;
    inputCleanup();

    return input;
}
