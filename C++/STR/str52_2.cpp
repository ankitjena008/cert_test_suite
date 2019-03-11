/*
In this noncompliant code example, data is invalidated after the call to replace(), and so its use in g() is undefined behavior.
*/

#include <iostream>
#include <string>
  
extern void g(const char *);
  
void f(std::string &exampleString) {
  const char *data = exampleString.data();
  // ...
  exampleString.replace(0, 2, "bb");
  // ...
  g(data);
}