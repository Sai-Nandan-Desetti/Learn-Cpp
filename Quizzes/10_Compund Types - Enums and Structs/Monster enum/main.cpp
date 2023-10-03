#include <iostream>
#include<typeinfo>

namespace monsters
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton
    };
}

int main()
{
    monsters::MonsterType monster { monsters::troll };    

    std::cout << "Monster type: " << typeid(decltype(monster)).name() << '\n';
    // std::cout << "You are a " << monster << '\n';

    return 0;
}
