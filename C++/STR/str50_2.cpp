/*
In this example, the first read will not overflow, but could fill bufOne with a truncated string. Furthermore, the second read still could overflow bufTwo.
*/

#include <iostream>
  
void f() {
  char bufOne[12];
  char bufTwo[12];
  std::cin.width(12);
  std::cin >> bufOne;
  std::cin >> bufTwo;
}

int main() {
	f();
	return 0;
}