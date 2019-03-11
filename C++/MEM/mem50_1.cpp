/*
In this noncompliant code example, s is dereferenced after it has been deallocated. If this access results in a write-after-free, the vulnerability can be exploited to run arbitrary code with the permissions of the vulnerable process. Typically, dynamic memory allocations and deallocations are far removed, making it difficult to recognize and diagnose such problems.
*/

#include <new>
  
struct S {
  void f();
};
  
void g() noexcept(false) {
  S *s = new S;
  // ...
  delete s;
  // ...
  s->f();
}

int main() {
	g();
	return 0;
}