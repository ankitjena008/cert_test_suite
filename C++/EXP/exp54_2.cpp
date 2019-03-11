/*
In this noncompliant code example, a pointer to an object is implicitly converted to a virtual base class after the object's lifetime has ended, resulting in undefined behavior.
*/

#include<iostream>
using namespace std;

struct B {};
  
struct D1 : virtual B {};
struct D2 : virtual B {};
  
struct S : D1, D2 {};
  
void f(const B *b) {}
  
void g() {
  S *s = new S;
  // Use s
  delete s;
  
  f(s);
}

int main() {
	g();
	return 0;
}