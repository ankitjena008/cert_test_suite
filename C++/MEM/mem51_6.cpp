/*
In this noncompliant code example, std::free() is called to deallocate memory that was allocated by new. A common side effect of the undefined behavior caused by using the incorrect deallocation function is that destructors will not be called for the object being deallocated by std::free().
*/

#include <cstdlib>
  
struct S {
  ~S();
};
 
void f() {
  S *s = new S();
  // ...
  std::free(s);
}

int main() {
	f();
	return 0;
}