#ifndef IO_H
#define IO_H

#include <string_view>

double getInput(std::string_view message);
void printBallHeight(const double seconds, const double result);
void printReached(const double seconds);
void printResult(const double seconds, const double result);

#endif
