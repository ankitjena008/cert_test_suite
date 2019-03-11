/*
In this noncompliant code example, the poly pointer value owned by a std::shared_ptr object is cast to the D * pointer type with dynamic_cast in an attempt to obtain a std::shared_ptr of the polymorphic derived type. However, this eventually results in undefined behavior as the same pointer is thereby stored in two different std::shared_ptr objects. When g() exits, the pointer stored in derived is freed by the default deleter. Any further use of poly results in accessing freed memory. When f() exits, the same pointer stored in poly is destroyed, resulting in a double-free vulnerability.
*/

#include <memory>
 
struct B {
  virtual ~B() = default; // Polymorphic object
  // ...
};
struct D : B {};
 
void g(std::shared_ptr<D> derived);
 
void f() {
  std::shared_ptr<B> poly(new D);
  // ...
  g(std::shared_ptr<D>(dynamic_cast<D *>(poly.get())));
  // Any use of poly will now result in accessing freed memory.
}

int main() {
	f();
	return 0;
}