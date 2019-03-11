/*
In this noncompliant code example, a nontrivial class object is initialized by calling its default constructor but is later reinitialized to its default state using std::memset(), which does not properly reinitialize the object. Improper reinitialization leads to class invariants not holding in later uses of the object.
*/

#include <cstring>
#include <iostream>
  
class C {
  int scalingFactor;
  int otherData;
  
public:
  C() : scalingFactor(1) {}
   
  void set_other_data(int i);
  int f(int i) {
    return i / scalingFactor;
  }
  // ...
};
  
void f() {
  C c;
   
  // ... Code that mutates c ...
   
  // Reinitialize c to its default state
  std::memset(&c, 0, sizeof(C));
   
  std::cout << c.f(100) << std::endl;
}

int main() {
  f();
  return 0;
}