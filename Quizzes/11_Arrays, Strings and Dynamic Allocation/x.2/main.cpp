#include <algorithm>
#include <vector>
#include <string_view>
#include <iostream>

struct Student
{
    std::string name{};
    int grade {};
};

using Students = std::vector<Student>;

int getNumberOfStudents()
{   
    int numberOfStudents{};
    do
    {
        std::cout << "How many students are there in your class? ";
        std::cin >> numberOfStudents;

    } while (numberOfStudents <= 0);
    
    return numberOfStudents;
}

void getStudents(Students& students)
{       
    for (int studentID{1}; Student& student : students)
    {
        std::cout << "\nStudent #" << studentID << '\n';
        
        std::cout << "Name: ";
        std::cin >> student.name; 
        // this is why you cannot use std::string_view for name
        // you cannot use cin on a read-only type

        std::cout << "Grade: ";
        std::cin >> student.grade;

        ++studentID;
    }
}

bool compareByGrade(const Student& s, const Student& t)
{
    return (s.grade > t.grade);
}

void print(const Students& students)
{
    for (const auto& student : students)    
        std::cout << student.name << " got a grade of " << student.grade << ".\n";    
}

int main()
{    
    int numberOfStudents{ getNumberOfStudents() };

    Students students(static_cast<Students::size_type>(numberOfStudents));

    getStudents(students);
    
    std::cout <<"\nThe students ordered in descending order of their grades:\n";
    std::sort(students.begin(), students.end(), compareByGrade);    
    print(students);

    return 0;
}
