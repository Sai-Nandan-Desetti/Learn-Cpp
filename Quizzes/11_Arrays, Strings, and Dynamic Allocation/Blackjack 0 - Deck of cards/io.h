#ifndef IO_H
#define IO_H

#include "suit.h"
#include "rank.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const CardRank& obj);
std::ostream& operator<<(std::ostream& out, const CardSuit& obj);

#endif
