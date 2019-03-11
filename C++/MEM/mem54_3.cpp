/*
This noncompliant code example attempts to allocate sufficient storage of the appropriate alignment for the array of objects of S.  However, it fails to account for the overhead an implementation may add to the amount of storage for array objects.  The overhead (commonly referred to as a cookie) is necessary to store the number of elements in the array so that the array delete expression or the exception unwinding mechanism can invoke the type's destructor on each successfully constructed element of the array.  While some implementations are able to avoid allocating space for the cookie in some situations, assuming they do in all cases is unsafe.
*/

#include <new>
 
struct S {
  S ();
  ~S ();
};
 
void f() {
  const unsigned N = 32;
  alignas(S) unsigned char buffer[sizeof(S) * N];
  S *sp = ::new (buffer) S[N];
  
  // ...
  // Destroy elements of the array.
  for (size_t i = 0; i != n; ++i) {
    sp[i].~S();
  }
}

int main() {
  f();
  return 0;
}