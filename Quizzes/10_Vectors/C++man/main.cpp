/**
 * @file main.cpp
 * @author DSN
 * @brief Play a game of C++man
 * @version 0.2
 * @date 2023-10-9 
 */

#include "random.h"
#include "game.h"
#include <string_view>
#include <vector>
#include <iostream>


namespace wordList
{
    using namespace std::literals::string_view_literals; // for sv suffix

    std::vector words{
        "mystery"sv, "broccoli"sv, "account"sv, "almost"sv, "spaghetti"sv,
        "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv
    };

    std::string_view getRandomWord()
    {                       
        return words[Random::get(0, words.size() - 1)];
    }
}

namespace setup
{
    std::string_view wordToGuess{ wordList::getRandomWord() };

    std::size_t getNumChances()
    {
        constexpr std::size_t minChances{ 4 };
        const std::size_t maxChances{ wordToGuess.size() };

        return Random::get(minChances, maxChances);
    }
}


int main()
{                   
    std::string_view word{ setup::wordToGuess };
    Game game{ word, setup::getNumChances() };    
    bool result{ game.play() };
    if (result)
        std::cout << "You WON!" << std::endl;
    else
    {
        std::cout << "Go and hang yourself.\n";
        std::string upperCaseWord(word.length(), '\0');
        std::transform(
            word.begin(), word.end(),
            upperCaseWord.begin(),
            [](char c){ return std::toupper(c); }
        );
        std::cout << "The word is \"" << upperCaseWord << "\"." << std::endl;
    }
        
    return 0;
}
