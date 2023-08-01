Q: When a function has a parameter (std::function& lambda), and say we are passing a lambda, that looks to me like we are passing a reference of the lambda to the function. But, this lesson says that in fact a copy is made. So what does that & mean and do here, and why ISN'T a reference passed?

A:
If a function wants a std::function, you can only give it a std::function. A lambda is not a std::function, but a std::function can be created from a lambda. When you pass a lambda to a function that wants a std::function, a temporary std::function will be created. If the function wants a const std::function&, a temporary std::function will be created and passed, by reference, to the function. Although you're passing the std::function by reference, a std::function has to be created to call the function.

```
void fn(const std::function&);
const auto lambda{ []{} };

// Creates a temporary std::function and passes it to @fn
fn(lambda);

// same as
fn(std::function{lambda});
```

If the lambda is large, ie. it captures many variables, converting it to a std::function is expensive. The prevent the lambda from being copied into to std::function,pass std::ref(lambda).
