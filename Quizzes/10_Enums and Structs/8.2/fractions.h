#ifndef FRACTIONS_H
#define FRACTIONS_H

struct  Fraction
{
    int numerator {};
    int denominator {1};
};

Fraction getFraction();
Fraction multiply(Fraction, Fraction);
void print(const Fraction&);

#endif
