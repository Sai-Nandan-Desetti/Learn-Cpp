#ifndef IO_H
#define IO_H

#include "animals.h"
#include "locomotion.h"
#include <iostream>
#include <limits>

std::istream& operator>>(std::istream& in, Animal& animal);
std::ostream& operator<<(std::ostream& out, Animal animal);
std::ostream& operator<<(std::ostream& out, Locomotion::Legs l);


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
    }
    else
    {
        ignoreLine(); // remove any extraneous input        
    }
}

#endif
