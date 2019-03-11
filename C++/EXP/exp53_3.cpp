/*
In this noncompliant code example, the class member variable c is not explicitly initialized by a ctor-initializer in the default constructor. Despite the local variable s being default-initialized, the use of c within the call to S::f() results in the evaluation of an object with indeterminate value, resulting in undefined behavior.
*/

#include<iostream>
using namespace std;

class S {
  int c;
  
public:
  int f(int i) const { return i + c; }
};
  
void f() {
  S s;
  int i = s.f(10);
}

int main() {
	f();
	return 0;
}