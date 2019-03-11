/*
In this noncompliant code example, a member variable of type std::initializer_list<int> is list-initialized within the constructor's ctor-initializer. Under these circumstances, the conceptual temporary array's lifetime ends once the constructor exits, so accessing any elements of the std::initializer_list<int> member variable results in undefined behavior.
*/

#include <initializer_list>
#include <iostream>
 
class C {
  std::initializer_list<int> l;
   
public:
  C() : l{1, 2, 3} {}
   
  int first() const { return *l.begin(); }
};
 
void f() {
  C c;
  std::cout << c.first();
}

int main() {
	f();
	return 0;
}