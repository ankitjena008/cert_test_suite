/*
In this noncompliant code example, std::memset() is used to clear the internal state of an object. An implementation may store a vtable within the object instance due to the presence of a virtual function, and that vtable is subsequently overwritten by the call to std::memset(), leading to undefined behavior when virtual method dispatch is required.
*/

#include <cstring>
 
struct S {
  int i, j, k;
  
  // ...
 
  virtual void f();
};
 
void f() {
  S *s = new S;
  // ...
  std::memset(s, 0, sizeof(S));
  // ...
  s->f(); // undefined behavior
}

int main() {
	f();
	return 0;
}