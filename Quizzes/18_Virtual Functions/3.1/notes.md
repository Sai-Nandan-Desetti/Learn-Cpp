**Output**:
```
BB
AA
AB
```

**Explanation**:
1. `D d{}`: `d` is an instance of `D`.
    - Consider the execution of `d.get().print()`. I believe the following steps occur:
        1. Since `d` is an *instance* of (not a *pointer* to or *reference* to) `D`, we know directly that `D::get()` is invoked; no need to check if `D::get()` is virtual or not.
        2. `D::get()` returns an anonymous reference (of type `B`) to `m_b` (which is, in turn, a `B` instance).
            - Let's call this reference `x`.
        3. `x` is used to call `print()`.
            - Since `x` is a reference and of type `B`, we check if `B::print()` is a virtual function.
            - It's not.
        4. So, invoke `B::print()`. It displays (the first) 'B'.
    - For the execution of `d.get().vprint()`:
        1. The action of `d.get()` is the same as above. It returns an anonymous reference that we chose to call `x` (for convenience).
        2. Since `x` is a reference and of type `B`, we check if `B::vprint()` is a virtual function.
            - It is.
            - Here we have a reference invoking a function; so, we need to find the most derived version of the function, i.e. `B::vprint()`.
                - When we talk about derivation, we need to have a start and an end point for it. If we derive `Q` from `P`, then `P` is the start point and `Q` is the end point.
            - The start point is given by the type of the pointer/reference.
            - The end point is given by the type of the object being pointed/referred to.
            - Here, `x` is the (anonymous) reference:
                - Its type is `B`. So, `B` is the start point.
                - It is referring to `m_b`, an instance of `B`. So, `B` is the end point.
            - Thus, `B::vprint()` is itself the most derived version of the function.
        3. So, invoke `B::vprint()`. It displays (the second) 'B'.

2. `C c{}`: `c` is an instance of `C`.
    - The execution of `c.get().print()` is entirely analogous to `d.get().print()`, with
        - `C` corresponding to `D`
        - `c` corresponding to `c`, and
        - `A` corresponding to `B`.        
    - For the execution of `c.get().vprint()`:
        1. Let's call the anonymous reference returned by `c.get()` as `y`.            
        2. Since `y` is a reference and the type of `y` is `A`, we check if `A::vprint()` is a virtual function.
            - It is.
            - What is the most derived version of `A::vprint()`?
                - The type of `y` is `A`. So, `A` is the start point.
                - It refers to `m_a`, an instance of `A`. So, `A` is itself the end point.                
                - Note that there's a derivation from `A` to `B` for `vprint()`. But we're not interested in that: our derivation begins and ends at `A`.
        3. Invoke `A::vprint()`. It displays (the second) 'A'.

3. `C& c{ d }`: `c` is of type `C` that refers to `d`, an instance of `D`.
    - Note that in the code `ref` is used instead of `c`.
    - Consider the execution of `c.get().print()`.
        1. Since `c` is a *reference* and of type `C`, we check if `C::get()` is a virtual function.
            - It is.
            - What is the most derived version of `C::get()`?
                - `c` is of type `C`. Thus, `C` is the start point.
                - `c` refers to `d`-- a `D` instance. Thus, `D` is the end point.
            - Therefore, `D::get()` is the most derived version.
        2. Invoke `D::get()`.
            - What does it return? This is where it gets tricky.
            - It returns the same type as the *actual* function is meant to return.
                - Here, we actually intended to execute `C::get()`.
                - Its return type is a reference to `A`.
            - Let's call the anonymous reference returned by `c.get()` as `z`.            
        3. Consider the execution of `z.print()`.
            - Since `z` is a reference and of type `A`, we check if `A::print()` is a virtual function.
            - It's not.
        4. Invoke `A::print()`. This displays 'A'.
    - For the execution of `c.get().vprint()`:
        1. As above, `D::get()` is invoked first and it returns an anonymous reference to `A`, which we call `z` for convenience.
        2. Since `z` is of type `A`, we check if `A::vprint()` is a virtual function.
            - It is.
            - What is the most derived version of `A::vprint()`?
                - `z` is of type `A`. So, the start point is `A`.
                - `z` refers to `m_b`, an instance of `B`. So, the end point is `B`.
            - Therefore, `B::vprint()` is the most derived version.
        3. Invoke `B::vprint()`. This displays 'B'.
