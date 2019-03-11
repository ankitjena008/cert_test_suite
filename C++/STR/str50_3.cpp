/*
In this noncompliant example, the unformatted input function std::basic_istream<T>::read() is used to read an unformatted character array of 32 characters from the given file. However, the read() function does not guarantee that the string will be null terminated, so the subsequent call of the std::string constructor results in undefined behavior if the character array does not contain a null terminator.
*/

#include <fstream>
#include <string>
  
void f(std::istream &in) {
  char buffer[32];
  try {
    in.read(buffer, sizeof(buffer));
  } catch (std::ios_base::failure &e) {
    // Handle error
  }
  
  std::string str(buffer);
  // ...
}

int main() {
	filebuf fb;
	if (fb.open ("test.txt",std::ios::in))
    {
      std::istream is(&fb);
      f(is);
      fb.close();
  }
  return 0;
}