/**
 * @file main.cpp
 * @author DSN
 * @brief A game to fight monsters
 * @version 0.6
 * @date 2023-10-04
 */

/**
 * @mainpage
 * A game to learn Inheritance in C++ on the pretext of fighting monsters.
 * 
 * <p>
 * Here are the rules for the game:
 * - The player encounters one randomly generated monster at a time.
 * - For each monster, the player has two choices: (R)un or (F)ight.
 * - If the player decides to Run, they have a 50% chance of escaping.
 * - If the player escapes, they move to the next encounter with no ill effects.
 * - If the player does not escape, the monster gets a free attack, and the player chooses their next action.
 * - If the player chooses to fight, the player attacks first. The monster’s health is reduced by the player’s damage.
 * - If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
 * - If the monster does not die, the monster attacks the player back. The player’s health is reduced by the monster’s damage.
 * - The game ends when the player has died (loss) or reached level 20 (win)
 * - If the player dies, the game should tell the player what level they were and how much gold they had.
 * - If the player wins, the game should tell the player they won, and how much gold they had.
 * 
 * <p>
 * Reference: [Learncpp: Inheritance](https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/)
*/

#include "player.h"
#include "game.h"
#include <iostream>
#include <string>
#include <algorithm> // transform
#include <cctype> // tolower


int main()
{
    std::cout << "Enter your name: ";
    std::string name{};
    std::cin >> name;

    // convert name to upper case
    std::transform(
        name.begin(),
        name.end(),
        name.begin(),
        [](unsigned char c)
        {
            return std::toupper(c);
        }
    );
    Player player{ name };
    std::cout << "Welcome, " << player.getName() << ".\n";

    Game::play(player);

	return 0;
}
