/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Randomly generates 5 monsters and displays them.
 * @version 0.1
 * @date 2023-08-18
 * 
 */

/**
 * @mainpage
 * Use the concepts of \c enum, \c class, and \c friend functions to randomly generate a few \c Monsters
 */


#include "monsterGenerator.h"
#include <iostream>


int main()
{
    for (int i{ 0 }; i < 5; ++i)
    {
        Monster m{ MonsterGenerator::generate() };
	    std::cout << m;
    }    

    return 0;
}
