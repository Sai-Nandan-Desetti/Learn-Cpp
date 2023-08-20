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

using Players = std::vector<Player*>;

static constexpr int playerLimit{ 21 };
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
    Players active_players{};

    /**
     * @brief A utility function to check if the game is over or not
     * 
     * @param deck 
     * @return true : there are atleast 2 players who are neither busted nor are standing
     * @return false : all (possibly but one) players are either busted or are standing
     */
    bool gameNotOver();

    int getMaxScore();
    
    /**
     * @brief Compute the outcome of each player
     * 
     */
    void computePlayerOutcomes();    

public:
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
