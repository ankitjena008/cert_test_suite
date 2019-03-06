#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <stdio.h>

enum { INTBUFSIZE = 80 };
enum { WCHAR_BUF = 128 };
 
extern int getdata(void);
int buf[INTBUFSIZE];
  
void func(void) {
  int *buf_ptr = buf;
 
  while (buf_ptr < (buf + sizeof(buf))) {
    *buf_ptr++ = getdata();
  }
}


struct big {
  unsigned long long ull_a;
  unsigned long long ull_b;
  unsigned long long ull_c;
  int si_e;
  int si_f;
};
 
void func1(void) {
  size_t skip = offsetof(struct big, ull_b);
  struct big *s = (struct big *)malloc(sizeof(struct big));
  if (s == NULL) {
    /* Handle malloc() error */
  }
 
  memset(s + skip, 0, sizeof(struct big) - skip);
  /* ... */
  free(s);
  s = NULL;
}

void func2(void) {
  wchar_t error_msg[WCHAR_BUF];
 
  wcscpy(error_msg, L"Error: ");
  fgetws(error_msg + wcslen(error_msg) * sizeof(wchar_t),
         WCHAR_BUF - 7, stdin);
  /* ... */
}


int main() {
	func();
	func1();
	func2();
	return 0;
}

