#include "operator.h"
#include <cassert>

bool isValid(Operator op)
{
    switch (op)
    {
    case add:
    case subtract:
    case multiply:
    case divide:
        return true;
    default:
        return false;
    }
}


Operator getOperator(char value)
{
    switch (value)
    {
    case '1':
    case '+':
        return add;
    case '2':
    case '-':
        return subtract;
    case '3':
    case '*':
        return multiply;
    case '4':
    case '/':
        return divide;
    default:
        return max_operators;
    }
}


char getName(Operator op)
{
    switch (op)
    {
    case add:
        return '+';        
    case subtract:
        return '-';
    case multiply:
        return '*';
    case divide:
        return '/';
    default:
        return '?';
    }
}
