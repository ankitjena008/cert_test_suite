/*
In the following noncompliant code example, the dynamically allocated memory managed by the buff object is accessed after it has been implicitly deallocated by the object's destructor.
*/

#include <iostream>
#include <memory>
#include <cstring>
  
int main(int argc, const char *argv[]) {
  const char *s = "";
  if (argc > 1) {
    enum { BufferSize = 32 };
    try {
      std::unique_ptr<char[]> buff(new char[BufferSize]);
      std::memset(buff.get(), 0, BufferSize);
      // ...
      s = std::strncpy(buff.get(), argv[1], BufferSize - 1);
    } catch (std::bad_alloc &) {
      // Handle error
    }
  }
 
  std::cout << s << std::endl;
}