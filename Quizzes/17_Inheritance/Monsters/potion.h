#ifndef POTION_H
#define POTION_H

#include <string_view>
#include <iostream>

/**
 * @brief Potions a player is allowed to drink (with 30% probability) in between the game.
 */
enum class Potion
{
    health,
    strength,
    poison,
    max_potions
};

std::string_view getName(Potion);
int operator+(Potion);
std::ostream& operator<<(std::ostream&, Potion);

#endif
