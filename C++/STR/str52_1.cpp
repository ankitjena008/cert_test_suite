/*
This noncompliant code example copies input into a std::string, replacing semicolon (;) characters with spaces. This example is noncompliant because the iterator loc is invalidated after the first call to insert(). The behavior of subsequent calls to insert() is undefined.
*/

#include <string>
  
void f(const std::string &input) {
  std::string email;
 
  // Copy input into email converting ";" to " "
  std::string::iterator loc = email.begin();
  for (auto i = input.begin(), e = input.end(); i != e; ++i, ++loc) {
    email.insert(loc, *i != ';' ? *i : ' ');
  }
}

int main() {
	string s = "test";
	f(s);
	return 0;
}