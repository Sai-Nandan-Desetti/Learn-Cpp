/**
 * @file game.h
 * @author DSN
 * @brief Defines the \c Game
 * @version 0.3
 * @date 2023-10-10 
 */

#ifndef GAME_H
#define GAME_H

#include "ui.h"
#include <string>
#include <string_view>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

using Indexes = std::vector<std::size_t>;
void initPositions(std::map<char, Indexes>& positions, std::string_view word);

class Game
{
private:
    std::string_view m_computerWord;
    std::map<char, Indexes> m_computerWordMap;    
    std::string m_userWord;
    std::size_t m_lettersLeft;
    std::size_t m_chancesLeft;
    std::string m_chances;    

    bool lose();
    bool win();
    void evaluate(char guess) noexcept;
    
public:
    Game(
        std::string_view wordToGuess,
        std::size_t numberOfChances
    ) :
    m_computerWord{ wordToGuess },
    m_computerWordMap{},    
    m_userWord(m_computerWord.length(), '_'),
    m_lettersLeft{ m_userWord.size() },
    m_chancesLeft{ numberOfChances },
    m_chances(m_chancesLeft, '+')    
    {             
        initPositions(m_computerWordMap, m_computerWord);
    }

    char takeUserInput();
    bool play();
};

#endif
