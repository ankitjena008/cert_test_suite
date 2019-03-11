/*
In this noncompliant code example, a lambda object is stored in a function object, which is later called (executing the lambda) to obtain a constant reference to a value. The lambda object returns an int value, which is then stored in a temporary int object that becomes bound to the const int & return type specified by the function object. However, the temporary object's lifetime is not extended past the return from the function object's invocation, which causes undefined behavior when the resulting value is accessed.
*/

#include <functional>
  
void f() {
  auto l = [](const int &j) { return j; };
  std::function<const int&(const int &)> fn(l);
  
  int i = 42;
  int j = fn(i);
}

int main() {
	f();
	return 0;
}