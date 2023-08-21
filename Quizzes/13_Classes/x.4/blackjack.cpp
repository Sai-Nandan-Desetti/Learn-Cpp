/**
 * @file blackjack.cpp
 * @author DSN
 * @brief Defines the member functions of \c Blackjack
 * @version 0.4
 * @date 2023-08-19
 * 
 */

#include "blackjack.h"
#include "user.h"
#include "dealer.h"
#include "outcome.h"
#include <algorithm>

/**
 * @details
 *  - Each player in \c m_players is reset.
 *  - \c active_players is cleared and re-initialized with the reset players.
 * 
 */
void Blackjack::resetPlayers()
{           
    active_players.clear();

    for (auto& player : m_players)
    {
        player->reset();
        active_players.push_back(player);
    }        
}

/**
 * @details
 *  - The game is not over if
 *      - there is more than one player who isn't busted, AND
 *      - there's is atleast one person who isn't standing.
 *  
 */
bool Blackjack::gameNotOver()
{        
    bool someoneCanHit{ false };

    for (auto& player : active_players)
        if (not player->isStand())    
        {
            player->chance(m_deck);
            someoneCanHit = true;
        }

    // Use a lambda expression to remove if player->isBusted()
    active_players.erase(
        std::remove_if(active_players.begin(), active_players.end(),
            [](const auto& player) { return player->isBusted(); }),
    active_players.end());

    return active_players.size() > 1 and someoneCanHit;
}

/**
 * @details
 *  - Compare only the scores of players not busted, which is conveniently stored in \c active_players
 */
int Blackjack::getMaxScore()
{   
    // Use a lambda expression to compare the players by their scores.
    auto winner = std::max_element(active_players.begin(), active_players.end(),
                    [](const auto& a, const auto& b) { return a->getScore() < b->getScore(); });

    return (*winner)->getScore();
}

/**
 * @details
 *  - A player is a winner if and only if his score matches the one calculated by \c maxScore()
 */
void Blackjack::computePlayerOutcomes()
{       
    std::cout << "\n----- SCORES ------\n";

    int maxScore{ getMaxScore() };

    for (auto& player : m_players)
    {
        std::cout << player->getName() << "'s score: " << player->getScore() << '\n';
        player->setOutcome((player->getScore() == maxScore) ? WIN : LOSE);
    }        
}

void Blackjack::displayResult()
{
    std::cout << "\n----- RESULTS ------\n";

    for (auto& player : m_players)
    {
        std::cout << player->getName();

        switch (player->getOutcome())
        {
        case WIN:
            std::cout << ": WON!\n";
            break;    
        default:
            std::cout << ": lost.\n";
            break;
        }
    }
}

/**
 * @details
 *  - Each \c User is first \c hit twice.
 *  - You play while \c gameNotOver
 *  - Once it's over, you \c computePlayerOutcomes
 */
void Blackjack::play()
{   
    m_deck.shuffle();
    
    for (std::size_t i{ 1 }; i < m_numPlayers; ++i)
    {
        m_players.at(i)->hit(m_deck);
        m_players.at(i)->hit(m_deck);
    }

    while (gameNotOver());

    computePlayerOutcomes();
}
