/*
In this noncompliant code example, the global operator new(std::size_t) function is replaced by a custom implementation. However, the custom implementation fails to honor the behavior required by the function it replaces, as per the C++ Standard, [new.delete.single], paragraph 3. Specifically, if the custom allocator fails to allocate the requested amount of memory, the replacement function returns a null pointer instead of throwing an exception of type std::bad_alloc. By returning a null pointer instead of throwing, functions relying on the required behavior of operator new(std::size_t) to throw on memory allocations may instead attempt to dereference a null pointer
*/

#include <new>
 
void *operator new(std::size_t size) {
  extern void *alloc_mem(std::size_t); // Implemented elsewhere; may return nullptr
  return alloc_mem(size);
}
  
void operator delete(void *ptr) noexcept; // Defined elsewhere
void operator delete(void *ptr, std::size_t) noexcept; // Defined elsewhere

int main() {
	return 0;
}