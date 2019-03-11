/*
In this noncompliant code example, a class with nontrivial initialization (due to the presence of a user-provided constructor) is created with a call to std::malloc(). However, the constructor for the object is never called, resulting in undefined behavior when the class is later accessed by calling s->f().
*/

#include <cstdlib>
 
struct S {
  S();
   
  void f();
};
 
void g() {
  S *s = static_cast<S *>(std::malloc(sizeof(S)));
  
  s->f();
  
  std::free(s);
}

int main() {
	g();
	return 0;
}