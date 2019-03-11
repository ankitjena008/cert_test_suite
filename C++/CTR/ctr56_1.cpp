/*
In this noncompliant code example, f() accepts an array of S objects as its first parameter. However, main() passes an array of T objects as the first argument to f(), which results in undefined behavior due to the pointer arithmetic used within the for loop.
*/

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
  for (const S *end = someSes + count; someSes != end; ++someSes) {
    std::cout << someSes->i << std::endl;
  }
}
 
int main() {
  T test[5];
  f(test, 5);
  return 0;
}