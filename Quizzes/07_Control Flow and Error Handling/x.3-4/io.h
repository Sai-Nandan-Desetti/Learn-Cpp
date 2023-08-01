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
    // Check for failed extraction
    if (!std::cin) // if the previous extraction failed
    {
        if (std::cin.eof()) // if the stream was closed
        {
            exit(0); // shut down the program now
        }

        // let's handle the failure
        std::cin.clear(); // put us back in 'normal' operation mode
        ignoreLine();     // and remove the bad input

        std::cout << "Invalid input! Please try again.\n";
    }
    else
    {
        ignoreLine(); // remove any extraneous input        
    }
}

#endif
