/*
In this noncompliant code example, the for loop uses array subscripting. Since array subscripts are computed using pointer arithmetic, this code also results in undefined behavior.
*/

#include <iostream>
  
// ... definitions for S, T, globI, globD ...
int globI;
double globD;
 
struct S {
  int i;
   
  S() : i(globI++) {}
};
 
struct T : S {
  double d;
   
  T() : S(), d(globD++) {}
};
 
void f(const S *someSes, std::size_t count) {
  for (std::size_t i = 0; i < count; ++i) {
    std::cout << someSes[i].i << std::endl;
  }
}
 
int main() {
  T test[5];
  f(test, 5);
}