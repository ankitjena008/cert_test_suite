/*
In the following noncompliant code example, an array is allocated with array new[] but is deallocated with a scalar delete call instead of an array delete[] call, resulting in undefined behavior.
*/

void f() {
  int *array = new int[10];
  // ...
  delete array;
}

int main() {
	f();
	return 0;
}