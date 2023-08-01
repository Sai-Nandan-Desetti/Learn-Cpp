#ifndef OPERATION_H
#define OPERATION_H

#include "operator.h"
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int _add(int, int);
int _subtract(int, int);
int _multiply(int, int);
int _divide(int, int);
ArithmeticFunction getArithmeticFunction(Operator op);

#endif
