#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include "pair.h"
#include <string_view>

template <typename U, typename T = std::string_view>
class StringValuePair : public Pair<T, U>
{
public:
    StringValuePair(T x, const U& y) : Pair<T, U>(x, y)
    {        
    }
    
};

#endif
