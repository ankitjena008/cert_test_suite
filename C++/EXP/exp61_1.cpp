/*
In this noncompliant code example, the function g() returns a lambda, which implicitly captures the automatic local variable i by reference. When that lambda is returned from the call, the reference it captured will refer to a variable whose lifetime has ended. As a result, when the lambda is executed in f(), the use of the dangling reference in the lambda results in undefined behavior.
*/

auto g() {
  int i = 12;
  return [&] {
    i = 100;
    return i;
  };
}
 
void f() {
  int j = g()();
}

int main() {
	f();
	return 0;
}