/*
In this noncompliant code example, a custom container class uses an allocator object to obtain storage for arbitrary element types. While the copy_elements() function is presumed to call copy constructors for elements being moved into the newly allocated storage, this example fails to explicitly call the default constructor for any additional elements being reserved. If such an element is accessed through the operator[]() function, it results in undefined behavior, depending on the type T.
*/

#include <memory>
 
template <typename T, typename Alloc = std::allocator<T>>
class Container {
  T *underlyingStorage;
  size_t numElements;
   
  void copy_elements(T *from, T *to, size_t count);
   
public:
  void reserve(size_t count) {
    if (count > numElements) {
      Alloc alloc;
      T *p = alloc.allocate(count); // Throws on failure
      try {
        copy_elements(underlyingStorage, p, numElements);
      } catch (...) {
        alloc.deallocate(p, count);
        throw;
      }
      underlyingStorage = p;
    }
    numElements = count;
  }
   
  T &operator[](size_t idx) { return underlyingStorage[idx]; }
  const T &operator[](size_t idx) const { return underlyingStorage[idx]; }
};

int main() {
  return 0;
}