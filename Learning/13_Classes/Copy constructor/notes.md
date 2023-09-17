**Implementing a copy constructor**:

* Let `a` and `b` be objects of type `T`.
* The operation of *creating* a copy of `a` for `b`[^1^] can be described as follows:    
    * Create an instance `b` of type `T` (to hold the `a` copy).
    * Copy the contents of `a` to `b` (ensure it's a deep copy in case a member accesses dynamically allocated memory).
        * Say if `T` has a member `ptr` that points to an array, then each of the elements pointed to by `a.ptr` must be copied to the storage pointed to by `b.ptr`.
    
* `T(const T& a)`:
    * I've kept the parameter name too as `a` for simplicity.
    * The type of the parameter (here, `a`):
        * Why const lvalue *reference*?        
            * We cannot pass by value. Because that would create a copy and would again have to call the copy constructor!
            * Because `a` is a reference, and references are not objects, when it goes out of scope, it does not call its destructor.
        * Why *const* lvalue reference?
            * We don't want the object we're copying from to be destroyed. Hence the `const` qualifier.
        * Why const *lvalue* reference?
            * A const lvalue reference can bind to both lvalues and rvalues.
    * To create an instance `b`, you can use a delegating default constructor or member-initialize here itself.

[^1^]: We're *creating* a `b` here. It didn't exist before.
