**What is the difference between putting the `const` keyword before and after a function's signature?**

1. No `const`:
```cpp
class Something
{
public:
    // Returns a reference to a std::string.
    // getValue() is not callable on const objects.
    std::string& getValue();
};

Something a{};
a.getValue(); // ok
a.getValue() = "rishi"; // ok

const Something b{};
b.getValue(); // illegal, @b is const but @getValue is not const.
```

2. `const` before the return type:
```cpp
class Something
{
public:
    // Returns a const reference to a std::string.
    // getValue() is not callable on const objects.
    const std::string& getValue();
};

Something a{};
a.getValue(); // ok
a.getValue() = "rishi"; // illegal, the returned reference is const.

const Something b{};
b.getValue(); // Illegal, @b is const but @getValue is not marked as const
```

3. `const` after the function signature:
```cpp
class Something
{
public:
    // Returns a non-const reference and is callable on const objects
    std::string& getValue() const;
};

Something a{};
a.getValue() = "hello"; // ok

const Something b{};
b.getValue() = "rishi"; // illegal
```

4. `const` before and after the function signature
```cpp
class Something
{
public:
    // Returns a const reference and is callable on const objects
    const std::string& getValue() const;
};

Something a{};
a.getValue(); // ok
a.getValue() = "rishi"; // illegal

const Something b{};
b.getValue(); // ok
b.getValue() = "rishi"; // illegal
```

**Reference**: [Const class objects and const member functions](https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/#comment-482982).
