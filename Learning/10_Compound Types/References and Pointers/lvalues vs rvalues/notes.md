## What are lvalues and rvalues?
* The **value category** of an expression (or subexpression) indicates whether an expression resolves to a value, a function, or an object of some kind.
* Prior to C++11, there were only two possible value categories: *lvalue* and *rvalue*. In C++11, three additional value categories (*glvalue*, *prvalue*, and *xvalue*) were added to support a new feature called *move semantics*.

**Definition of an lvalue**:
* An **lvalue** (pronounced “ell-value”, short for “left value” or “locator value”, and sometimes written as “l-value”) is an expression that evaluates to an *identifiable* object (or bit-field).
> The term “identity” is used by the C++ standard, but is not well-defined. An entity (such as an object or function) that has an identity can be differentiated from other similar entities (typically by comparing the addresses of the entity).
* What is the use of an identity?
    * Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a *lifetime longer than a single expression or statement*.

**Definition of an rvalue**:
* An **rvalue** (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) is an expression that is not an l-value.
> Commonly seen rvalues include literals (except C-style string literals, which are lvalues) and the return value of functions and operators that return by value.
* Rvalues aren’t identifiable (meaning they have to be used immediately), and only exist within the scope of the expression in which they are used.


**Distinguishing between lvalues and rvalues**:

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
