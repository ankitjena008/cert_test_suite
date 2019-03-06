#include <stdio.h>
  
/*In this noncompliant code example, the error_type argument to printf() is incorrectly matched with the s specifier rather than with the d specifier. */
void func1(void) {
  const char *error_msg = "Resource not available to user.";
  int error_type = 3;
  /* ... */
  printf("Error (type %s): %d\n", error_type, error_msg);
  /* ... */
}

int main() {
	func1();
}