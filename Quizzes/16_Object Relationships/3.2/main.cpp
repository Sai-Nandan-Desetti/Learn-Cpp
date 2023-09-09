#include "teacher.h"
#include "department.h"
#include <iostream>

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << "The department has the following teachers:\n";
        std::cout << department << '\n';

    } // department goes out of scope here and is destroyed

    std::cout << t1 << " still exists!\n";
    std::cout << t2 << " still exists!\n";
    std::cout << t3 << " still exists!\n";

    return 0;
}
