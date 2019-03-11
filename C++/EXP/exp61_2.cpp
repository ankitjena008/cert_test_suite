/*
In this noncompliant code example, a lambda reference captures a local variable from an outer lambda. However, this inner lambda outlives the lifetime of the outer lambda and any automatic local variables it defines, resulting in undefined behavior when an inner lambda object is executed within f().
*/

auto g(int val) {
  auto outer = [val] {
    int i = val;
    auto inner = [&] {
      i += 30;
      return i;
    };
    return inner;
  };
  return outer();
}
 
void f() {
  auto fn = g(12);
  int j = fn();
}

int main() {
  f();
  return 0;
}