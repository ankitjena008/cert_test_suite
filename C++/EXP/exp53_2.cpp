/*
In this noncompliant code example, an int * object is allocated by a new-expression, but the memory it points to is not initialized. The object's pointer value and the value it points to are printed to the standard output stream. Printing the pointer value is well-defined, but attempting to print the value pointed to yields an indeterminate value, resulting in undefined behavior.
*/

#include <iostream>
  
void f() {
  int *i = new int;
  std::cout << i << ", " << *i;
}

int main() {
	f();
	return 0;
}