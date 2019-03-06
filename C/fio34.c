#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <assert.h>
#include <limits.h>

/*This noncompliant code example loops while the character c is not EOF*/  
void func1(void) {
  int c;
  
  do {
    c = getchar();
  } while (c != EOF);
}

/*this code example is noncompliant because the variable c is declared as a char rather than an int, making it possible for a valid character value to compare equal to the value of the EOF macro when char is signed because of sign extension*/
void func2(void) {
  char c;
  static_assert(UCHAR_MAX < UINT_MAX, "FIO34-C violation");
 
  do {
    c = getchar();
  } while (c != EOF);
}

/*In this noncompliant example, the result of the call to the C standard library function getwc() is stored into a variable of type wchar_t and is subsequently compared with WEOF:*/
enum { BUFFER_SIZE = 32 };
 
void func3(void) {
  wchar_t buf[BUFFER_SIZE];
  wchar_t wc;
  size_t i = 0;
 
  while ((wc = getwc(stdin)) != L'\n' && wc != WEOF) {
    if (i < (BUFFER_SIZE - 1)) {
      buf[i++] = wc;
    }
  }
  buf[i] = L'\0';
}

int main() {
	func1();
	func2();
	func3();
	return 0;
}