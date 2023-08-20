/**
 * @file io.cpp
 * @author DSN
 * @brief Code file for \c io.h
 * @version 0.1
 * @date 2023-08-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "io.h"
#include <iostream>
#include <limits>


void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputCleanup()
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
