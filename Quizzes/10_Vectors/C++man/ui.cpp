#include "ui.h"
#include <limits> //std::numeric_limits

void UI::displayPrompt(std::string_view word, std::string_view chances)
{
    std::cout << "Word: " << word << '\t' << "Chances: " << chances << '\n';
    std::cout << "Your guess: ";
}

char UI::getUserGuess()
{
    char guess{};
    bool isValidGuess{};
    
    do
    {        
        isValidGuess = false;
        std::cin >> guess;

        if (std::islower(guess))        
            isValidGuess = true;
        else
        {
            std::cerr << "Invalid input. Please enter a character between 'a' and 'z'.\n";
            std::cout << "Your guess: ";
        }            
        // Clear any remaining characters from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (not isValidGuess);

    return guess;
}
