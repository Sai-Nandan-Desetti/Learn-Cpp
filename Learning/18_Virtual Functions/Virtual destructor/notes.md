**Why having a protected destructor doesn't allow the class to be allocated on the stack?**

```cpp
class Foo
{
public:
	Foo() {}
protected:
	~Foo() {}
};

int main()
{
	Foo f;

	return 0;
}
```
* When `f` is destroyed, `f.~Foo()` is called. If `~Foo()` isn't accessible (because it's protected), then it can't be called. The compiler should error.
