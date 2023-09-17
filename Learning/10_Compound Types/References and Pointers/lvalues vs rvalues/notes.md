## What are lvalues and rvalues?
* The **value category** of an expression (or subexpression) indicates the category of the value an expression resolves to.

**Definition of an lvalue**:
* When an expression evaluates to an *identifiable* object or function[^1^] (or bit-field), the identifiable object or function is called an **lvalue** (pronounced “ell-value”, short for “left value” or “locator value”, and sometimes written as “l-value”).
> The term “identity” is used by the C++ standard, but is not well-defined. An entity (such as an object or function) that has an identity can be differentiated from other similar entities (typically by comparing the addresses of the entity).
* What is the use of an identity?
    * Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a *lifetime longer than a single expression or statement*.

**Definition of an rvalue**:
* An **rvalue** (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) is a value that is not an l-value.[^2^]
> Commonly seen rvalues include literals (except C-style string literals, which are lvalues) and the return value of functions and operators that return by value.
* Rvalues aren’t identifiable (meaning they have to be used immediately), and only exist within the scope of the expression in which they are used.


### Distinguishing between lvalues and rvalues:

It seems like we can use `&` to distinguish between lvalues and rvalues because it requires an lvalue as an operand:


```cpp
#include <iostream>

int get5()
{
    return 5;
}

int main()
{        
    std::cout << &("Hello") << '\n'; // allowed; C-style string literals are lvalues!        
    
    std::cout << &(5) << '\n'; // error: lvalue required as unary '&' operand

    std::cout << &(get5()) << '\n'; // error: lvalue required as unary '&' operand

    return 0;
}

```

**An analogy**:

Imagine you received a gift from someone and you want to meet that person. If you can put a name to that someone, i.e. *identify the person* who sent you the gift, then you can *look up their address* and meet them. But if you have no idea who sent you that gift-- just an *anonymous*, mysterious benefactor-- then how can you find that person's address?

(Let's not extend the analogy to being a Sherlock Holmes and deriving clues from the gift... :))

**Notes**:
1. **r-values are objects that aren't identifiable. And objects are regions of storage in memory. So, they too should have an address, right?** They, of course, occupy some storage in memory. It's just that you can have no way of getting to know that address. Using the analogy above, the mysterious benefactor is, of course, living somewhere! We just don't (rather, can't) know where.

2. **What do you mean by the *identity* of an object?** The lesson says that the concept of an identity isn't well-defined but the identities of different entities can be differentiated (typically) by comparing their addresses. Like, the address itself isn't your identity; but it can be used to identify you in order to send you something.

### References
* [Learncpp - Value categories: lvalues and rvalues](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/)

[^1^]: Although an object is defined as a region of storage, a function is explicitly noted not to mean an object. See [What exactly is an object in C++?](https://stackoverflow.com/questions/43946981/what-is-exactly-an-object-in-c#:~:text=An%20object%20in%20C%2B%2B%20can,i%20is%20an%20object.)
[^2^]: Prior to C++11, there were only two possible value categories: *lvalue* and *rvalue*. In C++11, three additional value categories (*glvalue*, *prvalue*, and *xvalue*) were added to support a new feature called *move semantics*. Read [What are rvalues, lvalues, xvalues, glvalues, and prvalues?](https://stackoverflow.com/a/3601748) for a well-defined taxonomy of these values.

