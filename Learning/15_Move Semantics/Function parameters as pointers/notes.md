We want to make dumb pointers smart.

**How to make them smart?**
* By teaching them to clean up after themselves.
* The pointer must be deallocated once it goes out of scope.
* It should have automatic duration (RAII principle).

> RAII (Resource Acquisition Is Initialization) is a programming technique whereby resource use is tied to the lifetime of objects with automatic duration (e.g. non-dynamically allocated objects). In C++, RAII is implemented via classes with constructors and destructors. A resource (such as memory, a file or database handle, etc…) is typically acquired in the object’s constructor (though it can be acquired after the object is created if that makes sense). That resource can then be used while the object is alive. The resource is released in the destructor, when the object is destroyed. The primary advantage of RAII is that it helps prevent resource leaks (e.g. memory not being deallocated) as all resource-holding objects are cleaned up automatically.

* Ref: [Learncpp - Destructors](https://www.learncpp.com/cpp-tutorial/destructors/)

**Is that really *smart*?**
* As we see in the lesson, passing smart pointers to (or returning from) functions creates several problems.
* In contrast, we had no issues with "dumb" pointers.
Eg:
```cpp
#include <iostream>

struct Node
{
    int val{ 5 };
};

void print(Node* node)
{
    std::cout << node->val << '\n';
}

int main()
{
    Node* head{ new Node() };

    print(head);
    std::cout << head->val << '\n';
    
    delete head;

    return 0;
}

```
* `head` and `node` point to the same object. `node` goes out of scope once the control exits `print()`. But we can continue to use `head` to access `val`.
* What we want to achieve with a "smart" pointer is the equivalent of placing a `delete node` inside `print()`. Then, you wouldn't be able to use `head` to access `val` later.

**Conclusion**:
* Dumb and Smart pointers have their roles to play.
* **It's not always that you'd want to deallocate a pointer once it goes out of scope.**
* Don't expect smart pointers to *replace* the dumb ones (replace in every context, I mean).
