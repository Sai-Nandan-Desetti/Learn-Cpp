#include <iostream>
#include <string>
#include <string_view>

class Name
{
private:
    std::string m_name{};

public:    

    Name(std::string_view name) : m_name{ name }
    {
        std::cout << m_name << " Constructor called!\n";
    }

    Name(const Name& name) = delete;
    Name& operator=(const Name& name) = delete;

    // Create our own swap friend function to swap the members of Name
    friend void swap(Name& a, Name& b) noexcept
    {
        // We avoid recursive calls by invoking std::swap on the std::string member,
        // not on Name
        std::swap(a.m_name, b.m_name);
    }

    Name(Name&& name)
    {
        std::cout << "Move ctor\n";

        swap(*this, name); // Now calling our swap, not std::swap
    }

    /**
     * @details
     * Even if you were to receive by value here, it seems that object creation is elided.
     * 
     */
    Name& operator=(Name&& name)
    {
        std::cout << "Move assign\n";

        swap(*this, name); // Now calling our swap, not std::swap

        return *this;
    }

    std::string_view get() { return m_name; }
};

int main()
{
    Name n1{ Name{ "Alex" } }; // temporary object creation is elided
    n1 = Name{ "Joe" }; // invokes move assignment
    n1 = { "Root" }; // invokes move assignment

    std::cout << n1.get() << '\n';

    return 0;
}
