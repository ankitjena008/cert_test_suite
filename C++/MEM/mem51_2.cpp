/*
In this noncompliant code example, two allocations are attempted within the same try block, and if either fails, the catch handler attempts to free resources that have been allocated. However, because the pointer variables have not been initialized to a known value, a failure to allocate memory for i1 may result in passing ::operator delete() a value (in i2) that was not previously returned by a call to ::operator new(), resulting in undefined behavior.
*/

#include <new>
  
void f() {
  int *i1, *i2;
  try {
    i1 = new int;
    i2 = new int;
  } catch (std::bad_alloc &) {
    delete i1;
    delete i2;
  }
}

int main() {
	f();
	return 0;
}