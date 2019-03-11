/*
In this noncompliant code example, the call to malloc() is mixed with a call to delete.
*/

#include <cstdlib>

void f() {
  int *i = static_cast<int *>(std::malloc(sizeof(int)));
  // ...
  delete i;
}

int main() {
	f();
	return 0;
}