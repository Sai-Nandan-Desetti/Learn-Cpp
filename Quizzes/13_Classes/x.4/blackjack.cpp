/**
 * @file blackjack.cpp
 * @author DSN
 * @brief Defines the member functions of \c Blackjack
 * @version 0.3
 * @date 2023-08-19
 * 
 */

#include "blackjack.h"
#include "user.h"
#include "dealer.h"
#include "outcome.h"
#include <algorithm>


void Blackjack::resetPlayers()
{           
    active_players.clear();

    for (auto& player : m_players)
    {
        player->reset();
        active_players.push_back(player);
    }        
}

bool Blackjack::gameNotOver()
{        
    bool someoneCanHit{ false };

    for (auto& player : active_players)
        if (not player->isStand())    
        {
            player->chance(m_deck);
            someoneCanHit = true;
        }

    active_players.erase(
        std::remove_if(active_players.begin(), active_players.end(),
            [](const auto& player) { return player->isBusted(); }),
    active_players.end());

    return active_players.size() > 1 and someoneCanHit;
}

int Blackjack::getMaxScore()
{
    auto winner = std::max_element(active_players.begin(), active_players.end(),
                    [](const auto& a, const auto& b) { return a->getScore() < b->getScore(); });

    return (*winner)->getScore();
}

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
