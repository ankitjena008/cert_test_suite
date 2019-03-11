/*
In this noncompliant code example, an attempt is made to allocate zero bytes of memory through a call to operator new(). If this request succeeds, operator new() is required to return a non-null pointer value. However, according to the C++ Standard, [basic.stc.dynamic.allocation], paragraph 2 [ISO/IEC 14882-2014], attempting to dereference memory through such a pointer results in undefined behavior.
*/

#include <new>
 
void f() noexcept(false) {
  unsigned char *ptr = static_cast<unsigned char *>(::operator new(0));
  *ptr = 0;
  // ...
  ::operator delete(ptr);
}

int main() {
	f();
	return 0;
}