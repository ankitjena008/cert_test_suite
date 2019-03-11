/*
In this noncompliant code example, a std::unique_ptr is declared to hold a pointer to an object, but is direct-initialized with an array of objects. When the std::unique_ptr is destroyed, its default deleter calls delete instead of delete[], resulting in undefined behavior.
*/

#include <memory>
 
struct S {};
 
void f() {
  std::unique_ptr<S> s{new S[10]};
}

int main() {
	f();
	return 0;
}