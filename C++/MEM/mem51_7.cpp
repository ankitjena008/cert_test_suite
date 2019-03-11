/*
In this noncompliant code example, the global new operator is overridden by a class-specific implementation of operator new(). When new is called, the class-specific override is selected, so S::operator new() is called. However, because the object is destroyed with a scoped ::delete operator, the global operator delete() function is called instead of the class-specific implementation S::operator delete(), resulting in undefined behavior.
*/

#include <cstdlib>
#include <new>
  
struct S {
  static void *operator new(std::size_t size) noexcept(true) {
    return std::malloc(size);
  }
   
  static void operator delete(void *ptr) noexcept(true) {
    std::free(ptr);
  }
};
 
void f() {
  S *s = new S;
  ::delete s;
}

int main() {
	f();
	return 0;
}