#include <iostream>

int main(int argc, char* argv[])
{    
    // [[maybe_unused]] char s[] = "smooth";

    // s = c; // not allowed; `s` must be a modifiable lvalue
    // s[4] = 'c'; // allowed to modify values

    /* cannot simply put char* here*/
    // [[maybe_unused]] const char* c = "criminal";

    // c[2] = 'y'; // error: assignment of read-only location '*(c + 2)'
    // c = s; // allowed to redirect

    /* You have to put const here */
    // const char* strings[] = { "str0", "str1" };    
    /* It's suprising that for argv it doesn't mind that I don't keep */ 

    std::cout << argc << ' ' << argv[0] << '\n'; // argv[0] is the executable file's name

    return 0;
}
