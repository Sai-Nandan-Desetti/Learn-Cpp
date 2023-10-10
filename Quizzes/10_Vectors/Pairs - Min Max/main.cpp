#include <vector>
#include <utility>
#include <iostream>

template <typename T>
auto findMinMaxIndices(const std::vector<T>& elements)
{
    using Index = std::vector<T>::size_type;

    // we assume that there's at least one element in the vector
    Index minIndex{ 0 };
    Index maxIndex{ 0 };

    for (Index i{ 1 }; i < elements.size(); ++i)
        if (elements.at(i) < elements[minIndex])        
            minIndex = i;
        else if (elements.at(i) > elements[maxIndex])
            maxIndex = i;
    
    return std::make_pair(minIndex, maxIndex);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
    out << '(';
    using Index = std::vector<T>::size_type;
    for (Index i{ 0 }; i < vec.size() - 1; ++i)
        out << vec[i] << ", ";
    out << vec.back() << ')';

    return out;
}

int main()
{
    std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };    
    std::cout << "With array " << v1 << ":\n";
    auto m1{ findMinMaxIndices(v1) };
    std::cout << "The min element is at index " << m1.first << " and has value " << v1[m1.first] << "\n";    
    std::cout << "The max element is at index " << m1.second << " and has value " << v1[m1.second] << "\n";

    std::cout << std::endl;

    std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    std::cout << "With array " << v2 << ":\n";
    auto m2{ findMinMaxIndices(v2) };
    std::cout << "The min element is at index " << m2.first << " and has value " << v2[m2.first] << "\n";    
    std::cout << "The max element is at index " << m2.second << " and has value " << v2[m2.second] << "\n";

    std::cout << std::endl;
    
    std::cout << "Array of integers (to stop taking input, enter -1):\n";
    int input{};
    std::vector<int> v3;
    while(true)
    {
        std::cin >> input;
        if (input != -1)
            v3.push_back(input);
        else
            break;
    }
    std::cout << "With array " << v3 << ":\n";
    auto m3{ findMinMaxIndices(v3) };
    std::cout << "The min element is at index " << m3.first << " and has value " << v3[m3.first] << "\n";    
    std::cout << "The max element is at index " << m3.second << " and has value " << v3[m3.second] << "\n";

    return 0;
}
