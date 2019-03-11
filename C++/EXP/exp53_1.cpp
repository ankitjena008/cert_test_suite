/*
In this noncompliant code example, an uninitialized local variable is evaluated as part of an expression to print its value, resulting in undefined behavior.
*/

#include <iostream>
  
void f() {
  int i;
  std::cout << i;
}

int main() {
	f();
	return 0;
}