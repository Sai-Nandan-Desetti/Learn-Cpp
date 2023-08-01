#include "io.h"


std::istream& operator>>(std::istream& in, Animal& animal)
{
    int input {};
    in >> input;

    animal = static_cast<Animal>(input);
    return in;
}


std::ostream& operator<<(std::ostream& out, Animal animal)
{
    return out << getValue(animal);
}


std::ostream& operator<<(std::ostream& out, Locomotion::Legs l)
{
    return out << getValue(l);
}
