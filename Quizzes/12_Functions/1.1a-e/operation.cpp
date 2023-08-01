#include "operation.h"

int _add(int x, int y)
{
    return x + y;
}

int _subtract(int x, int y)
{
    return x - y;
}

int _multiply(int x, int y)
{
    return x * y;
}

int _divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(Operator op)
{
    switch (op)
    {
    case add:
        return _add;
    case subtract:
        return _subtract;
    case multiply:
        return _multiply;
    case divide:
        return _divide;
    default:
        return nullptr;
    }
}
