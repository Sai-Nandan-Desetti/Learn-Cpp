#include <iostream>

int main()
{   
    #if 0
    char str[]{"Hello World!"};    
    for (int i{0}; str[i] != '\0'; ++i)    
        std::cout << str[i];    
    #endif

    const char* str{"Hello World!"};    
    for (; *str != '\0'; ++str)
        std::cout << *str;
    std::cout << '\n';

    return 0;
}
