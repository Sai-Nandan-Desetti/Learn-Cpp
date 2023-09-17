**Implementing a move constructor**:

* Let `a` and `b` be instances of `T`.
* The operation of *creating* an instance by *moving* the contents of `a` to `b`[^1^] can be described as follows:
    * Create a default instance of `T`.
    * "Move" the contents of `a` to `b`.
    * Destroy `a` (that's one of the points of *move*).
        
* The naive way to move would be to copy the contents of `a` to `b` and then destroy `a`.
* But the main point of *move* is to avoid making a copy!

* `T(T&& a)`:
    * I've kept the parameter name too as `a` for simplicity.
    * The type of the parameter:
        * Why a reference to an rvalue?
            * We generally like to copy lvalues and move rvalues.
                * When we have `T b{ a }` (here, `a` is an lvalue), we do not want to destroy `a`. We should be able to continue using `a`. So, we *copy* `a` to `b`.
                * Now, suppose `x` is something that's needed to construct `T`. In the expression `b{ T{ x } }`, a temporary instance of `T` (an rvalue) is created using `x`. It is temporary in the sense that it has expression scope. We cannot use it beyond the expression. So, it's safe to *move* its contents to `b`, i.e. destroy the contents of the temporary object.
            * So, in this explanation `a` could be an rvalue. I've given it a name because I need to be able to explain this damn thing!
    * Create an instance of `T`:
        * You can delegate the task to another constructor.         
        * Typically we delegate to the default constructor.        
    * Swap the contents of `a` and `*this`[^2^].
        * We can simply swap. No deep copying here.
        * Whenever `a` (here, I mean `a` as in the oject that we intend to move from; not the local parameter of the constructor) goes out of scope, it destroys the default contents of `b`, whereas `b` itself has the contents we intended to move from `a`.        

[^1^]: `b` didn't exist before. We're creating it here using `a`.
[^2^]: `*this`. is `b`.
