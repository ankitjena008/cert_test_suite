
/*
This noncompliant code example uses a C-style variadic function to add a series of integers together. The function reads arguments until the value 0 is found. Calling this function without passing the value 0 as an argument (after the first two arguments) results in undefined behavior. Furthermore, passing any type other than an int also results in undefined behavior
*/

#include <cstdarg>
using namespace std;
 
int add(int first, int second, ...) {
  int r = first + second; 
  va_list va;
  va_start(va, second);
  while (int v = va_arg(va, int)) {
    r += v;
  }
  va_end(va);
  return r;
}

int main() {
	int a = 1;
	int b = 2;
	int x = add(a, b);
	return 0;
}