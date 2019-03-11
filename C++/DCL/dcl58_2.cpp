/*
In this noncompliant code example, a template specialization of std::plus is added to the namespace std in an attempt to allow std::plus to concatenate a std::string and MyString object. However, because the template specialization is of a standard library–provided type (std::string), this code results in undefined behavior.
*/
#include <functional>
#include <iostream>
#include <string>
 
class MyString {
  std::string data;
   
public:
  MyString(const std::string &data) : data(data) {}
   
  const std::string &get_data() const { return data; }
};
 
namespace std {
template <>
struct plus<string> : binary_function<string, MyString, string> {
  string operator()(const string &lhs, const MyString &rhs) const {
    return lhs + rhs.get_data();
  }
};
}
 
void f() {
  std::string s1("My String");
  MyString s2(" + Your String");
  std::plus<std::string> p;
   
  std::cout << p(s1, s2) << std::endl;
}

int main() {
  f();
  return 0;
}