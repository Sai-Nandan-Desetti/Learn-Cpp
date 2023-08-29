#ifndef CAR_H
#define CAR_H

#include <string>
#include <string_view>
#include <compare>
#include <iostream>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model) : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car&, const Car&) = default;
    friend std::strong_ordering operator<=>(const Car&, const Car&);
    friend std::ostream& operator<<(std::ostream& out, const Car&);
};

#endif
