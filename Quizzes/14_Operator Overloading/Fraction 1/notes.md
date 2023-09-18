* If we remove the `const` from the `Fraction * Fraction` operator, the following line from the main function no longer works.
```
// The non-const multiplication operator looks like this
Fraction operator*(Fraction& f1, Fraction& f2)

// This doesn't work anymore
Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
```
* We’re multiplying temporary `Fraction` objects, but non-const references cannot bind to temporaries.
