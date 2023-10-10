/**
 * @file ui.h
 * @author DSN
 * @brief Defines the user interface for the game
 * @version 0.2
 * @date 2023-10-10
 */

#ifndef UI_H
#define UI_H

#include <string_view>
#include <iostream>

namespace UI
{
    void displayPrompt(std::string_view word, std::string_view chances);
    char getUserGuess();
};

#endif
