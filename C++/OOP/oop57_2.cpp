/*
In this noncompliant code example, std::memcpy() is used to create a copy of an object of nontrivial type C. However, because each object instance attempts to delete the int * in C::~C(), double-free vulnerabilities may occur because the same pointer value will be copied into c2.
*/

#include <cstring>
  
class C {
  int *i;
  
public:
  C() : i(nullptr) {}
  ~C() { delete i; }
  
  void set(int val) {
    if (i) { delete i; }
    i = new int{val};
  }
  
  // ...
};
  
void f(C &c1) {
  C c2;
  std::memcpy(&c2, &c1, sizeof(C)); 
}

int main() {
  C c1 = new C();
  int a = 5;
  c1.i = &a;
  f(c1);
  return 0;
}