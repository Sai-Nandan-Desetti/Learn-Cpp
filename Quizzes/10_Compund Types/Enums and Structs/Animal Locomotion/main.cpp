/**
 * @file main.cpp
 * @author DSN
 * @brief Given an animal, print the number of legs it has.
 * @version 0.1
 * @date 2023-07-06
 */


/**
 * @mainpage
 * 
 * Given an animal from the user, display how many legs that animal has.
 * 1. Define an enum class \c Animal with the animals: pig, chicken, goat, cat, dog, and duck.
 * 2. Provide these animals as a list of options for the user to select from.
 * The options must be numbered starting from 1.
 * 3. Overload the \c operator>> so that you take in an \c Animal from the user.
 * 4. Define a function \c isAnimal() to check for the validity of the input.
 * Keep asking the user for input until they enter a valid animal.
 * 5. Define an enum \c Legs inside a namespace \c Locomotion
 * with the following constants: apod, biped, quadruped, hexaped, octoped.
 * 6. Define a function \c getLocomotion() that returns
 * whether a given animal is a \c biped, or a \c quadruped, etc.
 * Use a switch case; keep the default value as \c apod.
 * 7. Overload the \c operator<< to print the animal's name and the number of legs it has.
 * Eg: A chicken is a biped. Print "A chicken has 2 legs."    
 * 8. Ask the user if he wants to check for any other animal (y/n). Check for valid input.
 * If \c 'y', repeat. If \c 'n', exit.
 * \n 
 * - Functions pertaining to animals must be in \c animals.cpp
 * - Functions pertaining to locomotion must be in \c locomotion.cpp
 * - Functions pertaining to i/o must be in \c io.cpp
 * - Each source code file must have its corresponding header file.
 */

#include "animals.h"
#include "locomotion.h"
#include "io.h"
#include <iostream>

int main()
{
    using enum Animal;    

    char option {};       
    do
    {                   
        std::cout << "Choose an animal:\n";
        std::cout << "1. Pig\n";
        std::cout << "2. Chicken\n";
        std::cout << "3. Goat\n";
        std::cout << "4. Cat\n";
        std::cout << "5. Dog\n";
        std::cout << "6. Duck\n";

        Animal animal {};        
        do
        {   
            std::cout << "\nChoice: ";
            std::cin >> animal;
            inputCleanup();

        } while (!isAnimal(animal));
                        
        Locomotion::Legs legs { getLocomotion(animal) };
        std::cout << "A " << animal << " has " << legs << " legs.\n";        

        do
        {
            std::cout << "Would you like to check an animal again (y/n)? ";
            std::cin >> option;
            inputCleanup();

        } while (option != 'y' && option != 'n');

    } while (option == 'y');
    
    return 0;
}
