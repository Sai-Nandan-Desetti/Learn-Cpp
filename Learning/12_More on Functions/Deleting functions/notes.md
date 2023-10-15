* This lesson talks about disallowing *certain* type conversions.
It makes me wonder is there a way to disallow *any* type conversion; like, in this example here, ensure that `printInt` can be called only with an int as the argument?
(Something like the equivalent of `explicit`for fundamental data types, I guess.)

* Yes, add this:
```cpp
template <typename T>
void printInt(T x) = delete;
```
`printInt(int)` will be preferred when the argument is an int, but the function template will be preferred for everything else. Since the function template is deleted, it will generate a compile error.
