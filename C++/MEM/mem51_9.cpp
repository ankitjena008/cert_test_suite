/*
In this noncompliant code example, a std::shared_ptr is declared to hold a pointer to an object, but is direct-initialized with an array of objects. As with std::unique_ptr, when the std::shared_ptr is destroyed, its default deleter calls delete instead of delete[], resulting in undefined behavior.
*/

#include <memory>
 
struct S {};
 
void f() {
  std::shared_ptr<S> s{new S[10]};
}

int main() {
	f();
	return 0;
}