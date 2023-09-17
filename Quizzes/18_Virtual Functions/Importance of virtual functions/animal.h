#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
    std::string m_name;
    std::string m_speak;

    /**
     * @brief Construct a new \c Animal
     * @details
     * We're making this constructor protected 
     * because we don't want people creating Animal objects directly,
     * but we still want derived classes to be able to use it.
     * 
     * @param name
     * @param speak 
     */
    Animal(
        std::string_view name,
        std::string_view speak
    ):
    m_name{ name },
    m_speak{ speak }
    {
    }

    // To prevent slicing
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

#endif
