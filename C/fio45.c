#include <stdio.h>

/*If an existing file is opened for writing with the w mode argument, the file's previous contents (if any) are destroyed. This noncompliant code example tries to prevent an existing file from being overwritten by first opening it for reading before opening it for writing. An attacker can exploit the race window between the two calls to fopen() to overwrite an existing file.*/
void open_some_file(const char *file) {
  FILE *f = fopen(file, "r");
  if (NULL != f) {
    /* File exists, handle error */
  } else {
    if (fclose(f) == EOF) {
      /* Handle error */
    }
    f = fopen(file, "w");
    if (NULL == f) {
      /* Handle error */
    }
  
    /* Write to file */
    if (fclose(f) == EOF) {
      /* Handle error */
    }
  }
}

int main() {
	open_some_file('temp.txt');
	return 0;
}