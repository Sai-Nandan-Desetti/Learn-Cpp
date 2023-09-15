**How does the compiler match a given function call to a specific overloaded function?**

**The argument matching sequence**:
1. The compiler tries to find an **exact match**. This happens in two phases.
    1. The compiler will see if there is an overloaded function where the type of the arguments in the function call exactly matches the type of the parameters in the overloaded functions. 
    2. The compiler will apply a number of *trivial* conversions to the arguments in the function call. The trivial conversions are a set of specific conversion rules that will modify types (without modifying the value) for purposes of finding a match.

2. If no exact match is found, the compiler tries to find a match by applying **numeric promotion** to the argument(s).

3. If no match is found via numeric promotion, the compiler tries to find a match by applying **numeric conversions**.

4. If no match is found via numeric conversion, the compiler tries to find a match through any **user-defined conversions**.

5. If no match is found via user-defined conversion, the compiler will look for a matching function that uses **ellipsis**.

6. If no matches have been found by this point, the compiler gives up and will issue a **compile error** about not being able to find a matching function.
