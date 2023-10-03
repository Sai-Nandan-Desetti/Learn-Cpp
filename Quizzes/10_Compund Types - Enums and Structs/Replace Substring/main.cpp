#include <iostream>
#include <string>

/**
 * @brief Replaces all occurrences of a substring in a given string with another string.
 *
 * @param str The target string to perform replacements on.
 * @param to_replace The substring to replace.
 * @param replace_with The replacement string.
 */
void replaceSubstring(std::string& str, const std::string& to_replace, const std::string& replace_with)
{
    std::size_t startPos {0};
    std::size_t foundPos;
    while ((foundPos = str.find(to_replace, startPos)) != std::string::npos)
    {
        str.replace(foundPos, to_replace.length(), replace_with);
        startPos = foundPos + replace_with.length();
    }
}

int main()
{
    std::string str { "I saw a red car yesterday." };
    std::string to_replace { "red" };
    std::string replace_with { "blue" };

    replaceSubstring(str, to_replace, replace_with);

    std::cout << str << '\n';

    return 0;
}
