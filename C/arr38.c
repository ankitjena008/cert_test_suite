#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
  
static const char str[] = "Hello world";
static const wchar_t w_str[] = L"Hello world";

/*
In this noncompliant code example, the incorrect element count is used in a call to wmemcpy(). 
The sizeof operator returns the size expressed in bytes, but wmemcpy() uses an element count based on wchar_t *.
*/
void func(void) {
  char buffer[32];
  wchar_t w_buffer[32];
  memcpy(buffer, str, sizeof(str)); /* Compliant */
  wmemcpy(w_buffer, w_str, sizeof(w_str)); /* Noncompliant */
}

/*
This noncompliant code example assigns a value greater than the number of bytes of 
available memory to n, which is then passed to memset()
*/
void f1(size_t nchars) {
  char *p = (char *)malloc(nchars);
  /* ... */
  const size_t n = nchars + 1;
  /* ... */
  memset(p, 0, n);
}

/*
In this noncompliant code example, the element count of the array a is ARR_SIZE elements. Because memset() expects a byte count, 
the size of the array is scaled incorrectly by sizeof(int) instead of sizeof(long), which can form an invalid pointer on architectures 
where sizeof(int) != sizeof(long).
*/
void f2(void) {
  const size_t ARR_SIZE = 4;
  long a[ARR_SIZE];
  const size_t n = sizeof(int) * ARR_SIZE;
  void *p = a;
 
  memset(p, 0, n);
}

/*
In this noncompliant code example, the value of n is incorrectly computed, allowing a read past the end of the object referenced by q
*/
void f4() {
  char p[40];
  const char *q = "Too short";
  size_t n = sizeof(p);
  memcpy(p, q, n);
}

struct obj {
  char c;
  long long i;
};

void func2(FILE *f, struct obj *objs, size_t num_objs) {
  const size_t obj_size = 16;
  if (num_objs > (SIZE_MAX / obj_size) ||
      num_objs != fwrite(objs, obj_size, num_objs, f)) {
    /* Handle error */
  }
}

void func3(FILE *file) {
  enum { BUFFER_SIZE = 1024 };
  wchar_t wbuf[BUFFER_SIZE];
 
  const size_t size = sizeof(*wbuf);
  const size_t nitems = sizeof(wbuf);
 
  size_t nread = fread(wbuf, size, nitems, file);
  /* ... */
}


int main()
{
	func();
	f1(10);
	f2();
	f4();
  struct obj *temp = malloc(sizeof(struct obj));
  FILE *fp = fopen("temp.txt", 'r');
  func2(fp, temp, 8);
  func3(fp);
  fclose(fp);
	return 0;
}




