/*
Because the input is unbounded, the following code could lead to a buffer overflow.
*/

#include <iostream>
  
void f() {
  char buf[12];
  std::cin >> buf;
}

int main() {
	f();
	return 0;
}