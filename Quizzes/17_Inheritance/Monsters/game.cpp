#include "game.h"
#include "io.h"
#include "random.h"
#include <iostream>

/**
 * @details
 * Generate a 0 or 1 using a uniformly distributed randomly variable to simulate a 50% probability of fleeing.
 *  - 0: You have to fight.
 *  - 1: You managed to escape.
 */
bool Game::canEscape()
{
    return static_cast<bool>(Random::get(0, 1));
}

/**
 * @details
 * The probability of finding a potion must be 30%.
 *  - A number in the range [0,9] is randomly (and uniformly) generated.
 *  - There's a 30% chance that the number would be in [0,3).
 *  - Conveniently, I've defined only three potions.
 *      - So, the number can be used directly to get the corresponding potion.
 */
int Game::potionFound()
{    
    int p{ Random::get(0, 9) };

    return p < +Potion::max_potions ? p : -1;    
}

void Game::play(Player &player)
{
    do
    {
        Monster monster{ Monster::getRandomMonster() };
        std::cout << player.getName() <<" has encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
        
        char choice{};
        do
        {
            std::cout << "Run or Fight (r/f): ";            
            std::cin >> choice;
            IO::inputCleanup();
        } while (not (choice == 'r' or choice == 'f'));

        if (choice == 'r')
        {
            if(not canEscape())
            {
                std::cout << player.getName() <<" has failed to flee.\n";

                // The monster gets a free attack
                monster.attack(player);
            }
            else
                std::cout << player.getName() <<" has successfully fled.\n";
        }
        else if (choice == 'f')
        {
            // You attack the monster
            player.attack(monster);
            
            if (not monster.isDead())
            {
                // The monster attacks you back
                monster.attack(player);
            }
            else
            {
                // You killed the monster
                std::cout << player.getName() <<" has killed the " << monster.getName() << ".\n";

                // You increase a level
                player.levelUp();
                std::cout << player.getName() <<" is now at level " << player.getLevel() << ".\n";
                
                // and are rewarded with the monster's gold
                player.addGold(monster.getGold());
                std::cout << player.getName() <<" has found " << monster.getGold() << " gold.\n";
            }
        }
        
        // check if there's a potion for you
        int potionNumber{ potionFound() };
        if (potionNumber != -1)
        {
            std::cout << player.getName() << " has found a mythical potion.\n";          
            do
            {
                std::cout << "Drink? (y/n): ";
                std::cin >> choice;
                IO::inputCleanup();
            } while (not (choice == 'y' or choice == 'n'));
            
            if (choice == 'y')
                player.drink(static_cast<Potion>(potionNumber));
        }
        

    } while (not (player.isDead() or player.hasWon()));

    if (player.isDead())
    {
        std::cout << player.getName() <<" died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad he can't take it with him!\n";
    }        
    else
        std::cout << player.getName() <<" WON!\n";
}
