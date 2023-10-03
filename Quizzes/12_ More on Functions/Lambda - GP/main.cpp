#include <string_view>
#include <algorithm>
#include <array>
#include <iostream>

struct Student
{
    std::string_view name{};
    int points{};
};

int main()
{
    std::array<Student, 8> arr{
        {{"Albert", 3},
         {"Ben", 5},
         {"Christine", 2},
         {"Dan", 8},
         {"Enchilada", 4},
         {"Francis", 1},
         {"Greg", 3},
         {"Hagrid", 5}}
    };

    // this `auto` here is for the type of the lambda, which is not the return type
    // so, don't keep bool there!
    // If you do want to explicitly mention the return type, it should be done 
    // next to the parameter list
    auto compareByPoints_ASC{
        [](const Student& self, const Student& other) -> bool
        {
            return self.points < other.points;
        }
    };

    // if max_element() works fine, it returns a Student*
    // else, it could return arr.end() (or maybe something else)
    // hence, the need for `auto`
    auto topper{ std::max_element(arr.begin(), arr.end(), compareByPoints_ASC) };

    std::cout << topper->name << " is the best student.\n";

    return 0;
}
