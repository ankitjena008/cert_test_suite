/*
In this noncompliant code example, the local variable s1 is passed as the expression to the placement new operator. The resulting pointer of that call is then passed to ::operator delete(), resulting in undefined behavior due to ::operator delete() attempting to free memory that was not returned by ::operator new().
*/

#include <iostream>
  
struct S {
  S() { std::cout << "S::S()" << std::endl; }
  ~S() { std::cout << "S::~S()" << std::endl; }
};
  
void f() {
  S s1;
  S *s2 = new (&s1) S;
  
  // ...
  
  delete s2;
}

int main() {
	f();
	return 0;
}