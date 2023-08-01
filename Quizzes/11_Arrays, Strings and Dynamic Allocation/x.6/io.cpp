#include "io.h"

std::ostream& operator<<(std::ostream& out, const CardRank& obj)
{
    return out << getName(obj);
}

std::ostream& operator<<(std::ostream& out, const CardSuit& obj)
{
    return out << getName(obj);
}
