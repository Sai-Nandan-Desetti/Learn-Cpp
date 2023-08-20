/**
 * @file player.h
 * @author DSN
 * @brief Defines the contract for a \c Player
 * @version 0.2
 * @date 2023-08-19
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "outcome.h"
#include <string_view>

/**
 * @brief A player is defined by the score that he earns through his chances, in which he can either hit or stand.
 * 
 */
class Player
{
protected:
    std::string_view m_name{};
    const int m_limit{};
    int m_score{};
    bool m_stand{};
    bool m_busted{};
    Outcome m_outcome{};    

public:
    Player()
    {}
    
    Player(std::string_view name, const int playerLimit) 
    : m_name{ name }, m_limit{ playerLimit }, m_score{ 0 }, m_stand{ false }, m_busted{ false }, m_outcome{ LOSE }
    {}
    
    virtual ~Player() = default;
    
    /**
     * @brief Get the player's name
     * 
     * @return std::string_view 
     */
    std::string_view getName() const
    {
        return m_name;
    }

    /**
     * @brief Get the player's score
     * 
     * @return int 
     */
    int getScore() const
    {
        return m_score;
    }

    /**
     * @brief Return if a player is busted
     * 
     * @return true : if the player's score has crossed the given limit
     * @return false : the player isn't busted yet
     */
    bool isBusted() const
    {
        return m_busted;
    }

    /**
     * @brief Return if a player STANDS
     * 
     * @return true : if the players STANDS
     * @return false : the player HITS
     */
    bool isStand() const
    {
        return m_stand;
    }

    /**
     * @brief Set the player's outcome upon finishing the game
     * 
     * @param outcome 
     */
    void setOutcome(Outcome outcome)
    {
        m_outcome = outcome;
    }

    /**
     * @brief Get the outcome of the player's game
     * 
     * @return Outcome 
     */
    Outcome getOutcome() const
    {
        return m_outcome;
    }

    /**
     * @brief Reset the scores and status of the players (to play another game)
     * 
     */
    void reset()
    {
        m_score = 0;
        m_stand = false;
        m_busted = false;                
    }

    /**
     * @brief Defines the chance of a player.
     * 
     * @param deck      
     */
    virtual void chance(Deck& deck) = 0;

    /**
     * @brief Defines the actions performed when a player HITS (as opposed to STANDS).
     * 
     * @param deck 
     */
    virtual void hit(Deck& deck) = 0;    
};

#endif
