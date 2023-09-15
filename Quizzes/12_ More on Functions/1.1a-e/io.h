#ifndef IO_H
#define IO_H

#include "operator.h"
#include <iostream>

std::istream& operator>>(std::istream& in, Operator& op);
std::ostream& operator<<(std::ostream& out, Operator op);
void ignoreLine();
void inputCleanup();
int getInteger();

#endif
