/*
In this noncompliant code example, a null pointer-to-member value is passed as the second operand to a pointer-to-member expression, resulting in undefined behavior.
*/

struct B {
  virtual ~B() = default;
};
 
struct D : B {
  virtual ~D() = default;
  virtual void g() { /* ... */ }
};
  
static void (D::*gptr)(); // Not explicitly initialized, defaults to nullptr.
void call_memptr(D *ptr) {
  (ptr->*gptr)();
}
  
void f() {
  D *d = new D;
  call_memptr(d);
  delete d;
}

int main() {
	f();
	return 0;
}