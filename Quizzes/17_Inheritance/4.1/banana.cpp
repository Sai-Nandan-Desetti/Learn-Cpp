#include "banana.h"

std::ostream& operator<<(
    std::ostream& out,
    const Banana& banana
)
{
    out << "banana(" << banana.getName() << ", " << banana.getColor() << ")";
    return out;
}
