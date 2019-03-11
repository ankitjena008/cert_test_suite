/*
In this noncompliant code example, a pointer to an object is used to call a non-static member function of the object prior to the beginning of the pointer's lifetime, resulting in undefined behavior.
*/

#include<iostream>
using namespace std;
struct S {
  void mem_fn();
};
  
void f() {
  S *s;
  s->mem_fn();
}

int main() {
	f();
	return 0;
}