/**
 * @file monster.cpp
 * @author DSN
 * @brief Defines the member functions of the \c Monster class and other utility functions pertaining to it.
 * @version 0.1
 * @date 2023-08-18
 * 
 */

#include "monster.h"


std::ostream& operator<<(std::ostream& out, const Monster& monster)
{
    return out << monster.m_name << " the " << monster.m_type << " has "
               << monster.m_hitPoints << " hit points and says " << monster.m_roar << ".\n";
}
