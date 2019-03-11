/*
In this noncompliant code example, f() is called with an iterable range of objects of type S. These objects are copied into a temporary buffer using std::copy(), and when processing of those objects is complete, the temporary buffer is deallocated. However, the buffer returned by std::get_temporary_buffer() does not contain initialized objects of type S, so when std::copy() dereferences the destination iterator, it results in undefined behavior because the object referenced by the destination iterator has yet to start its lifetime. This is because while space for the object has been allocated, no constructors or initializers have been invoked.
*/

#include <algorithm>
#include <cstddef>
#include <memory>
#include <type_traits>
  
class S {
  int i;
 
public:
  S() : i(0) {}
  S(int i) : i(i) {}
  S(const S&) = default;
  S& operator=(const S&) = default;
};
 
template <typename Iter>
void f(Iter i, Iter e) {
  static_assert(std::is_same<typename std::iterator_traits<Iter>::value_type, S>::value,
                "Expecting iterators over type S");
  ptrdiff_t count = std::distance(i, e);
  if (!count) {
    return;
  }
   
  // Get some temporary memory.
  auto p = std::get_temporary_buffer<S>(count);
  if (p.second < count) {
    // Handle error; memory wasn't allocated, or insufficient memory was allocated.
    return;
  }
  S *vals = p.first;
   
  // Copy the values into the memory.
  std::copy(i, e, vals);
   
  // ...
   
  // Return the temporary memory.
  std::return_temporary_buffer(vals);
}

//Unsure about f's arguments