#ifndef OPERATOR_H
#define OPERATOR_H

enum class Operator
{
    add,
    subtract,
    multiply,
    divide,

    max_operators
};

using enum Operator;

bool isValid(Operator);
Operator getOperator(char value);
char getName(Operator op);

#endif
