/*
In this noncompliant code example, an array of int is created using ::operator new[](std::size_t) and the results of the allocation are not checked. The function is marked as noexcept, so the caller assumes this function does not throw any exceptions. Because ::operator new[](std::size_t) can throw an exception if the allocation fails, it could lead to abnormal termination of the program.
*/

#include <cstring>
  
void f(const int *array, std::size_t size) noexcept {
  int *copy = new int[size];
  std::memcpy(copy, array, size * sizeof(*copy));
  // ...
  delete [] copy;
}

int main() {
	int a[5] = {1,2,3,4,5};
	int x = 5;
	size_t s = (size_t) x;
	f(a, s);
	return 0;
}