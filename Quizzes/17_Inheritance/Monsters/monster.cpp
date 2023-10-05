#include "monster.h"
#include "random.h"
#include <array>

/**
 * @details
 * This function is used by the constructor to pass the relevant info to the base constructor.
 */
const Creature& Monster::getDefaultCreature(Type type)
{
    static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
    { 
        { "dragon", 'D', 20, 4, 100 },
        { "orc", 'o', 4, 2, 25 },
        { "slime", 's', 1, 1, 10 }
    }};

    return monsterData.at(static_cast<std::size_t>(type));
}

/**
 * @details
 * Use a Mersenne Twister to randomly generate a number in the range \c [0,Monster::Type::max_types-1]
 */
Monster Monster::getRandomMonster()
{
    int min{ 0 };
    int max{ static_cast<int>(max_types) - 1 };

    return { static_cast<Type>(Random::get(min, max)) };    
}
