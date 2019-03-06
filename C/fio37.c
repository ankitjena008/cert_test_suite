#include <stdio.h>
#include <string.h>
  
/*The strlen() function computes the length of a string by determining the number of characters that precede the terminating null character. A problem occurs if the first character read from the input by fgets() happens to be a null character. */  
enum { BUFFER_SIZE = 1024 };
 
void func1(void) {
  char buf[BUFFER_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
    /* Handle error */
  }
  buf[strlen(buf) - 1] = '\0';
}

int main() {
	func1();
}