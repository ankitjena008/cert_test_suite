/*
In this noncompliant code example, the address of a local variable is returned from f(). When the resulting pointer is passed to h(), the lvalue-to-rvalue conversion applied to i results in undefined behavior.Some compilers generate a diagnostic message when a pointer to an object with automatic storage duration is returned from a function, as in this example.
*/

#include<iostream>
using namespace std;

int *g() {
  int i = 12;
  return &i;
}
  
void h(int *i);
  
void f() {
  int *i = g();
  h(i);
}

int main(int argc, char const *argv[])
{
	f();
	return 0;
}