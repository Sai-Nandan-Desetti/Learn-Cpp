#ifndef IO_H
#define IO_H

#include <iostream>
#include <limits>

namespace IO
{
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
            
            std::cin.clear();
            ignoreLine();
        }
        else
            ignoreLine();
    }
}

#endif
