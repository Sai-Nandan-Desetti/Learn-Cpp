/**
 * @file blackjack.h
 * @author DSN
 * @brief Defines a 2-player ( \c User vs \c Dealer ) game of \c Blackjack
 * @version 0.4
 * @date 2023-08-19
 * 
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "player.h"
#include "deck.h"
#include <vector>

/**
 * @brief \c Players is a vector of \c Player addresses
 * @details
 *  - Run-time polymorphism requires us to use the base class address.
 * 
 */
using Players = std::vector<Player*>;

/**
 * @brief If a player's score reaches beyond this limit, he is busted.
 * 
 */
static constexpr int playerLimit{ 21 };

/**
 * @brief If the dealer's score reaches beyond this limit, he has to stand.
 * 
 */
static constexpr int dealerLimit{ 17 };

/**
 * @brief A game of Blackjack is defined by the players, a deck of cards, and a few parameters based on the rules.
 * 
 */
class Blackjack
{
private:
    Deck m_deck{};    
    std::size_t m_numPlayers{};
    Players m_players{};
    Players active_players{}; // holds the players not busted yet

    /**
     * @brief A utility function to check if the game is over or not
     * 
     * @param deck 
     * @return true : there are atleast 2 players who are neither busted nor are standing
     * @return false : all (possibly but one) players are either busted or are standing
     */
    bool gameNotOver();

    /**
     * @brief Get the maximum score among non-busted players
     * 
     * @return int 
     */
    int getMaxScore();
    
    /**
     * @brief Compute the outcome of each player
     * 
     */
    void computePlayerOutcomes();    

public:
    /**
     * @brief Initialize the players playing \c Blackjack
     * @details
     *  - Initially all players are active (naturally).
     * @param players
     *  
     */
    Blackjack(Players& players)
    {
        m_numPlayers = players.size();
        
        for (auto& player : players)
        {
            m_players.push_back(player);
            active_players.push_back(player);
        }
    }

    /**
     * @brief Reset each player
     * 
     */
    void resetPlayers();

    /**
     * @brief Play a game of \c Blackjack
     *      
     */
    void play();

    /**
     * @brief Display the result for each player
     * 
     */
    void displayResult();
};

#endif
