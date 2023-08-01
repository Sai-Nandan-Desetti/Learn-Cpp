#include <iostream>
#include <array>
#include <list>

template <typename T, std::size_t size>
void print(const std::array<T, size>& arr)
{
    for (auto a : arr)
        std::cout << a << ' ';

    std::cout << '\n';
}

int main()
{
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    // `i` is an unsigned integer type
    // so think about why the postfix operator is necessary here
    for (std::size_t i{ arr.size() }; i-- > 0;)
        std::cout << arr[i] << ' ';    
    std::cout << '\n';

    // Reverse iterate using rbegin() and rend()
    for (auto it{ arr.rbegin() }; it != arr.rend(); ++it)    
        std::cout << *it << ' ';
    std::cout << '\n';

    // Reverse by initializing with prev(end)
    // Note that you can compare iterator elements with `<` or `>`
    // only for those defined on random access containers like arrays    
    for (auto it{ std::prev(arr.end()) }; it >= arr.begin(); --it)
        std::cout << *it << ' ';
    std::cout << '\n';

    std::list<int> numList{1, 2, 3, 4, 5};
    // You can't use `>=` for a std::list
    // (which is actually a doubly linked list)
    // Have to use `!=`
    for (auto it{ std::prev(numList.end()) }; it != numList.begin(); --it)
        std::cout << *it << ' ';
    std::cout << '\n';
    // You can see the disadvantage of it. It doesn't print the first element.
    // That's why prefer `rbegin()` and `rend()`.

    return 0;
}
