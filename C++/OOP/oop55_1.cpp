/*
In this noncompliant code example, a pointer-to-member object is obtained from D::g but is then upcast to be a B::*. When called on an object whose dynamic type is D, the pointer-to-member call is well defined. However, the dynamic type of the underlying object is B, which results in undefined behavior.
*/

struct B {
  virtual ~B() = default;
};
 
struct D : B {
  virtual ~D() = default;
  virtual void g() { /* ... */ }
};
 
void f() {
  B *b = new B;
  
  // ...
  
  void (B::*gptr)() = static_cast<void(B::*)()>(&D::g);
  (b->*gptr)();
  delete b;
}

int main() {
	f();
	return 0;
}