/*
In this noncompliant code example, a std::shared_ptr of type S is constructed and stored in s1. Later, S::g() is called to get another shared pointer to the pointer value managed by s1. However, the smart pointer returned by S::g() is not related to the smart pointer stored in s1. When s2 is destroyed, it will free the pointer managed by s1, causing a double-free vulnerability when s1 is destroyed.
*/

#include <memory>
 
struct S {
  std::shared_ptr<S> g() { return std::shared_ptr<S>(this); }   
};
 
void f() {
  std::shared_ptr<S> s1 = std::make_shared<S>();
  // ...
  std::shared_ptr<S> s2 = s1->g();
}

int main() {
	f();
	return 0;
}