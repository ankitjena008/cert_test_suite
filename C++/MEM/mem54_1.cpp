/*
In this noncompliant code example, a pointer to a short is passed to placement new, which is attempting to initialize a long. On architectures where sizeof(short) < sizeof(long), this results in undefined behavior. This example, and subsequent ones, all assume the pointer returned by placement new will not be used after the lifetime of its underlying storage has ended. For instance, the pointer will not be stored in a static global variable and dereferenced after the call to f() has ended. 
*/

#include <new>
  
void f() {
  short s;
  long *lp = ::new (&s) long;
}

int main() {
	f();
	return 0;
}