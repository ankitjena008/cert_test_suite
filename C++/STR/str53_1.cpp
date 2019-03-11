/*
In this noncompliant code example, the value returned by the call to get_index() may be greater than the number of elements stored in the string, resulting in undefined behavior.
*/
#include <string>
  
extern std::size_t get_index();
  
void f() {
  std::string s("01234567");
  s[get_index()] = '1';
}

int main() {
	f();
	return 0;
}