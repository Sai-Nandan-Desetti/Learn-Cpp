#ifndef ANIMALS_H
#define ANIMALS_H

#include "locomotion.h"
#include <string_view>

enum class Animal
{
    pig = 1,
    chicken,
    goat,
    cat,
    dog,
    duck
};


bool isAnimal(Animal);
std::string_view getAnimalName(Animal);
std::string_view getValue(Animal);
Locomotion::Legs getLocomotion(Animal);

#endif
