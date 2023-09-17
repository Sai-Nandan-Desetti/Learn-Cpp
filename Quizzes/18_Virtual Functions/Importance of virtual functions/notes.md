- In this example, we needed a way to obtain derived class functionality using a pointer of the base class.
- And, particularly, we had to come up with a method without using virtual functions.
    - So that we can illustrate some of the fallacies in working around virtual functions,
    - Thereby underscoring the importance of virtual functions.
    
- What are the issues with the workaround we came up with?
    - `speak()` was one way to differentiate between a `Cat` and a `Dog`.
        - What if tomorrow we need more ways to differentiate between them? Would you add all that functionality as well to the base `Animal` class? Then, the base class could quickly become too complex and unmanageable.
    - Currently, `speak()` simply returns `m_speak`.
        - What if you wanted to implement `speak()` for a `Cat` and `Dog` differently? You'd have to try and implement that in the base class function!
