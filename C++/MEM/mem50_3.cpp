/*
In this noncompliant code example, std::string::c_str() is being called on a temporary std::string object. The resulting pointer will point to released memory once the std::string object is destroyed at the end of the assignment expression, resulting in undefined behavior when accessing elements of that pointer.
*/

#include <string>
  
std::string str_func();
void display_string(const char *);
  
void f() {
  const char *str = str_func().c_str();
  display_string(str);  /* Undefined behavior */
}

int main() {
	f();
	return 0;
}