/**
 * @file animals.cpp
 * @author DSN
 * @brief 
 * @version 0.1
 * @date 2023-07-06
 */


#include "animals.h"

using enum Animal;


bool isAnimal(Animal animal)
{
    switch(animal)
    {
        case pig:       
        case chicken:   
        case goat:      
        case cat:       
        case dog:       
        case duck:
            return true;
        default:
            return false;
    }
}


std::string_view getAnimalName(Animal animal)
{
    switch(animal)
    {
        case pig:       return "pig";
        case chicken:   return "chicken";
        case goat:      return "goat";
        case cat:       return "cat";
        case dog:       return "dog";
        case duck:      return "duck";
        default:        return "";    
    }
}


std::string_view getValue(Animal animal)
{
    return getAnimalName(animal);
}


Locomotion::Legs getLocomotion(Animal animal)
{    
    using Locomotion::Legs;

    switch(animal)
    {
        case pig:       return Legs::quadruped;
        case chicken:   return Legs::biped;
        case goat:      return Legs::quadruped;
        case cat:       return Legs::quadruped;
        case dog:       return Legs::quadruped;
        case duck:      return Legs::biped;
        default:        return Legs::apod;        
    }
}
