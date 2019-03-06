#include <stdlib.h>
#include <string.h>
#include <stdio.h>
  
enum { MAX_ALLOCATION = 1000 };

/*This noncompliant code example sets c_str to reference either dynamically allocated memory or a statically allocated string literal depending on the value of argc. In either case, c_str is passed as an argument to free(). If anything other than dynamically allocated memory is referenced by c_str, the call to free(c_str) is erroneous.*/ 
void func1(int argc, const char *argv[]) {
  char *c_str = NULL;
  size_t len;
  if (argc == 2) {
    len = strlen(argv[1]) + 1;
    if (len > MAX_ALLOCATION) {
      /* Handle error */
    }
    c_str = (char *)malloc(len);
    if (c_str == NULL) {
      /* Handle error */
    }
    strcpy(c_str, argv[1]);
  } else {
    c_str = "usage: $>a.exe [string]";
    printf("%s\n", c_str);
  }
  free(c_str);
}

/*In this noncompliant example, the pointer parameter to realloc(), buf, does not refer to dynamically allocated memory*/
enum { BUFSIZE = 256 };
  
void func2(void) {
  char buf[BUFSIZE];
  char *p = (char *)realloc(buf, 2 * BUFSIZE);
  if (p == NULL) {
    /* Handle error */
  }
}

int main(int argc, char* argv[]) {
  func1(argc, argv);
  func2();
}
