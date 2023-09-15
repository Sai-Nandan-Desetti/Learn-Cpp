#include "monsters.h"
#include "io.h"
#include <iostream>
#include <string>

int main()
{
    char option {};
    do
    {
        std::cout << "Enter the type of monster you want to initialize:\n";
        std::cout << "1. Ogre\n";
        std::cout << "2. Dragon\n";
        std::cout << "3. Orc\n";
        std::cout << "4. Giant spider\n";
        std::cout << "5. Slime\n";
        std::cout << "\nChoice: ";

        MonsterType monsterType {};
        std::cin >> monsterType;

        std::cout << "Monster's name: ";
        std::string name {};
        std::cin >> name;
        inputCleanup();

        std::cout << "Monster's health: ";
        int health {};
        std::cin >> health;

        Monster monster { monsterType, name, health };
        printMonster(monster);

        do
        {
            std::cout << "Do you want to create more monsters? (y/n) ";
            std::cin >> option;
            inputCleanup();

        } while (option != 'y' && option != 'n');        

    } while (option == 'y');
    
    return 0;
}
