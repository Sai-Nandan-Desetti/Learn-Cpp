/**
 * @file user.cpp
 * @author DSN
 * @brief Defines the member functions of \c User
 * @version 0.1
 * @date 2023-08-19
 * 
 */

#include "user.h"
#include "io.h"
#include <iostream>


void User::chance(Deck& deck)
{                    
    char option{};
    std::cout << "\nHIT or STAND? (h/s): ";
    std::cin >> option;
    inputCleanup();

    if (option == 's')
        m_stand = true;
    else
        hit(deck);    

    if (m_score > m_limit)
        m_busted = true;
}

void User::hit(Deck& deck)
{
    const Card card{ deck.dealCard() };
    std::cout << "Card: " << card;    

    m_score += card.getCardValue();
    if (card.getRank() == rank_ace and m_score > m_limit)
        m_score -= 10;
    
    std::cout << "\nCurrent score: " << m_score << '\n';
}
