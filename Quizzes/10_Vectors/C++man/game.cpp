#include "game.h"

void initPositions(std::map<char, Indexes>& positions, std::string_view word)
{
    using Index = std::size_t;
    for (Index i{}; i < word.size(); ++i)    
        positions[word[i]].push_back(i);    
}

bool Game::lose()
{
    return m_chancesLeft == 0;
}

bool Game::win()
{
    return m_lettersLeft == 0;
}

void Game::evaluate(char guess) noexcept
{
    try
    {
        // operator[] doesn't do bounds check
        // you need `at` here for an exception to be thrown when the key is missing.
        for (const auto& pos : m_computerWordMap.at(guess))
        {
            m_userWord[pos] = guess;
            --m_lettersLeft;
        }
            
    }
    catch(const std::out_of_range& e)
    {        
        m_chances[--m_chancesLeft] = guess;
    }
    
}

char Game::takeUserInput()
{
    UI::displayPrompt(m_userWord, m_chances);
    return UI::getUserGuess();
}

bool Game::play()
{
    do
    {
        char userGuess{ takeUserInput() };
        evaluate(userGuess);

    } while (not (win() or lose()));
    
    return win();
}
