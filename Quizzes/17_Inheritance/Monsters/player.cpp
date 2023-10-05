#include "player.h"
#include <iostream>

int Player::getLevel() const
{
    return m_level;
}

void Player::levelUp()
{
    m_level += 1;    
    m_damage += 1;
    // to be able to access Creature::m_damage directly we need to define it
    // with a protected access specifier in the Creature class.
}

bool Player::hasWon() const
{
    return m_level == s_MAX_LEVEL;
}
