#include "creature.h"
#include <iostream>

std::string_view Creature::getName() const
{
    return m_name;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getDamage() const
{
    return m_damage;
}

int Creature::getGold() const
{
    return m_gold;
}

void Creature::reduceHealth(int reduceBy)
{
    m_health -= reduceBy;
}

bool Creature::isDead() const
{
    return m_health <= 0;
}

void Creature::addGold(int increaseBy)
{
    m_gold += increaseBy;
}

void Creature::attack(Creature& other)
{
    other.reduceHealth(this->m_damage);
    std::cout << this->m_name << " hit " << other.m_name << " for " << this->m_damage << " damage.\n";
}
