**Pointers and const**:

```cpp
int main()
{
    int v{ 5 };

    int* ptr0 { &v };             // points to an "int" but is not const itself, so this is a normal pointer.
    const int* ptr1 { &v };       // points to a "const int" but is not const itself, so this is a pointer to a const value.
    int* const ptr2 { &v };       // points to an "int" and is const itself, so this is a const pointer (to a non-const value).
    const int* const ptr3 { &v }; // points to an "const int" and is const itself, so this is a const pointer to a const value.

    // if the const is on the left side of the *, the const belongs to the value
    // if the const is on the right side of the *, the const belongs to the pointer

    return 0;
}
```

* How to remember the syntax?
    * Space out the `*`.
    * Replace `*` with "points to" and read backwards.    

2. `const int* ptr1{ &v }`:
    * Put a space between `int` and `*`: `const int * ptr1{ &v }`
    * `ptr1`, a pointer, *points to* a `const int`.

3. `int* const ptr2{ &v }`:
    * Put a space between `int` and `*`: `int * const ptr2{ &v }`
    * `const ptr2`, a const pointer, *points to* an integer.

* This distinction is useful when the pointer is pointing to an *array* of elements.
    * Case 2:
        * You CANNOT *modify* the elements it's pointing to.
            * Yeah, it's pointing only to the first element; but my point is that it cannot be used to reference other elements in the array and modify them.
        * You CAN *redirect* the pointer to point to another array.        
    * Case 3:
        * You CAN modify the elements it has access to.
        * You CANNOT redirect it to point to another array.
    * This distinction is best highlighted between char* and char[] when they are initialized with a string literal.
