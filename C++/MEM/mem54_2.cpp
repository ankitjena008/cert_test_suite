/*
This noncompliant code example ensures that the long is constructed into a buffer of sufficient size. However, it does not ensure that the alignment requirements are met for the pointer passed into placement new. To make this example clearer, an additional local variable c has also been declared.
*/

#include <new>
  
void f() {
  char c; // Used elsewhere in the function
  unsigned char buffer[sizeof(long)];
  long *lp = ::new (buffer) long;
  
  // ...
}

int main() {
	f();
	return 0;
}