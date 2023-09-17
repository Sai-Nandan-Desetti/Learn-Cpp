**Implementing an overloaded assignment operator**:

* Let's say `a` and `b` are objects of type `T`.
* The operation of *assigning* `a` to `b`[^1^] can be described as follows:
    * Destroy the contents of `b` (anyway it's going to be overwritten).    
    * Copy the contents of `a` to `b` (ensure it's a deep copy in case a member accesses dynamically allocated memory).        

* `T& T::operator=(T a)`:
    * I've kept the parameter name too as `a` for simplicity.
    * The type of the parameter `a`:
        * Why *pass by value*?
            * We need to *copy* the contents of `a` to `b`. Why not let the copy constructor do that? Why rewrite the logic here?
            * When you pass by value, a (deep) copy is created, for which the copy constructor is invoked.
    * Swap the contents of `*this`[^2^] and `a`.
        * Note that we need to destory the contents of `b`.
        * **And since `a` is a local variable and an object (rather than a reference), when it goes out of scope its destructor is invoked**.
        * By swapping the contents of `a` and `b`, `a` now contains `b`'s contents and `b` contains `a`'s contents. So, when `a`'s destructor is called `b`'s contents get destroyed, while at the same time since `a` was holding the contents that we intended to copy to `b` those contents are indeed now with `b`!
    * The return value:
        * Why return a *reference*?
            * For chaining multiple assignments.

[^1^]: `b` already exists. We're only rewriting its contents.
[^2^]: `*this` is `b`. Since we're assigning `a` to `b`, `b` invokes the `operator=` method.
