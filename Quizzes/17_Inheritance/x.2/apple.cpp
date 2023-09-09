#include "apple.h"

std::ostream& operator<<(
    std::ostream& out,
    const Apple& apple
)
{
    out << "Apple(" << apple.getName() << ", " << apple.getColor() << ")";
    return out;
}
