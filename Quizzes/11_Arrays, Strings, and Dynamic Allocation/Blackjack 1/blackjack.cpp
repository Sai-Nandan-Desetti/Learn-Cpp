#include "blackjack.h"
#include "io.h"
#include <functional>

constexpr int gameLimit{21};

using Player = int;

Card getTop(const Deck& deck)
{
    static std::size_t top{0};

    return deck[top++];
}

namespace User
{    
    bool stand{false};

    void hit(const Deck& deck, Player& player)
    {
        Card card{ getTop(deck) };
        std::cout << "Card: ";
        printCard(card);        

        player += getValue(card);
        std::cout << "\nCurrent score: " << player << '\n';
    }

    bool chance(const Deck& deck, Player& player)
    {                
        if (player <= gameLimit)
        {
            char option{};
            std::cout << "\nHIT or STAND? (h/s): ";
            std::cin >> option;
            inputCleanup();

            if (option == 's')
                stand = true;
            else
                hit(deck, player);            
        }

        return player <= gameLimit;
    }
}

namespace Dealer
{
    constexpr int playerLimit{17};
    bool stand{false};

    void hit(const Deck& deck, Player& player)
    {
        Card card{ getTop(deck) };
        player += getValue(card);
    }

    bool chance(const Deck& deck, Player& player)
    {        
        if (player <= gameLimit)
        {
            if (player >= playerLimit)
                stand = true;
            else
                hit(deck, player);            
        }

        return player <= gameLimit;
    }
}

void printScores(const Player& dealer, const Player& user)
{
    std::cout << "\n\nDealer score: " << dealer << '\n';
    std::cout << "Your score: " << user << '\n';    
}

Outcome getOutcome(const Player& dealer, const Player& user)
{
    return static_cast<Outcome>(user <= gameLimit and (dealer > gameLimit or user >= dealer));
}

Outcome playBlackjack(const Deck& deck)
{
    Player dealer{0};
    Player user{0};        

    User::hit(deck, user);
    User::hit(deck, user);

    Dealer::hit(deck, dealer);

    while (not Dealer::stand and not User::stand)
        if (not User::chance(deck, user) or not Dealer::chance(deck, dealer))
            goto GAME_OVER;

    while (not Dealer::stand)
        if (not Dealer::chance(deck, dealer))
            goto GAME_OVER;

    while (not User::stand)
        if (not User::chance(deck, user))
            goto GAME_OVER;

    GAME_OVER:
    printScores(dealer, user);
    return getOutcome(dealer, user);
}
