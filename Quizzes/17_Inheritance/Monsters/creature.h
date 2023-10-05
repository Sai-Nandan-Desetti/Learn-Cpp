/**
 * @file creature.h
 * @author DSN
 * @brief Defines a \c Creature
 * @version 0.1
 * @date 2023-10-05 
 */

#ifndef CREATURE_H
#define CREATURE_H

#include <string_view>

class Creature
{
protected:
    std::string_view m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    // Creature() = default;    
    
    Creature(
        std::string_view name, 
        char symbol, 
        int health, 
        int damage, 
        int gold
    ) : 
    m_name{ name }, 
    m_symbol{ symbol }, 
    m_health{ health }, 
    m_damage{ damage }, 
    m_gold{ gold }
    {        
    }

    // Getters for private members
    std::string_view getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getDamage() const;
    int getGold() const;

    /**
     * @brief Reduces the \c Creature's health by an integer amount.
     * 
     * @param reduceBy: amount to reduce the Creature's health by. 
     */
    void reduceHealth(int reduceBy);
    
    /**
     * @brief A \c Creature is dead if its health is 0 or less.
     * 
     * @return true: DEAD 
     * @return false: NOT YET 
     */
    bool isDead() const;

    /**
     * @brief Increases the amount of \c Creature's gold by a given amount.
     * 
     * @param increaseBy: amount to increase by. 
     */
    void addGold(int increaseBy);

    /**
     * @brief \c other's health is reduced by the damage inflicted by \c *this.
     * 
     * @param other 
     */
    void attack(Creature& other);
};

#endif
