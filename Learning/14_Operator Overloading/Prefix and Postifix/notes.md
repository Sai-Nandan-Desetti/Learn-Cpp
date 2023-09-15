## About the modulo operator

### Only division
* You don't really implement the modulo operator. You only implement division.
* Given two numbers `a` and `b`, `a/b` must satisfy
```
a == (b * (a / b) + r)
```
for some remainder `r`.
* When you want to evalutate `a % b`, whatever value fits this `r`, that's what is returned.

#### The case when a or b is negative
* For some architectural reasons, the decision was taken to *round non-integer quotients to zero*.
    * This has the following effect on negative numbers (integers as well as non-integers).
        * Eg. The quotient of `(-7) / 3` is `-2` and the remainder is `-7 - (-6) = -1`.
        * Mathematically, negative remainders are disallowed.
            * How can you subtract `-6` (larger number) from `-7` (smaller number)?
            * We should instead have
                * Quotient: `-3` and Remainder: `-7 - (-9) = 2`
                * With non-integer quotients, this happens when you *round down*, i.e. the value after the rounding will be lower than before (in contrast to rounding to 0).
        * Eg. The quotient of `7 / (-3)` is `-2` and the remainder is `7 - 6 = 1`
        * Here, it matches with math.
* I suppose this was done to ensure that the division operation is made symmetric. Maybe that makes it more efficient to implement in hardware.
    * And since division apparently occurs more frequently than modulo, the optimization must've been accepted.
* Thus, C, and in turn C++, followed the same convention. (Python, for one, doesn't.)

### How to align with math?
* Conditional operator: `r = a % b < 0 ? r + b : r`
* Dual modulo: `((a % b) + b) % b`

## References
* [Modulo operator with negative values [duplicate]](https://stackoverflow.com/questions/7594508/modulo-operator-with-negative-values)
* [Why does C++ output negative numbers when using modulo?](https://stackoverflow.com/questions/11630321/why-does-c-output-negative-numbers-when-using-modulo)
* [Modulus with negative numbers in C++ [duplicate]](https://stackoverflow.com/questions/12276675/modulus-with-negative-numbers-in-c/)
