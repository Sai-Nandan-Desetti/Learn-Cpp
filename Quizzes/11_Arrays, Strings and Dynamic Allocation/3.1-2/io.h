#ifndef IO_H
#define IO_H

#include <iostream>
#include <limits>

inline void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void inputCleanup()
{
    if (!std::cin)
    {
        if (std::cin.eof())
            exit(0);
        else
        {
            std::cin.clear();
            ignoreLine();
        }    
    }
    else
        ignoreLine();   
}

#endif
