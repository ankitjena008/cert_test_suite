/*
This noncompliant code example attempts to replace the initial character in the string with a capitalized equivalent. However, if the given string is empty, the behavior is undefined.
*/

#include <string>
#include <locale>
 
void capitalize(std::string &s) {
  std::locale loc;
  s.front() = std::use_facet<std::ctype<char>>(loc).toupper(s.front());
}

int main() {
	string s = "test";
	capitalize(test);
	return 0;
}