#include <string.h>
#include <stdio.h>
#include <stddef.h>
  
/*In this noncompliant code example, control reaches the end of the checkpass() function when the two strings passed to strcmp() are not equal, resulting in undefined behavior.*/
int checkpass(const char *password) {
  if (strcmp(password, "pass") == 0) {
    return 1;
  }
}
 
void func(const char *userinput) {
  if (checkpass(userinput)) {
    printf("Success\n");
  }
}

size_t getlen(const int *input, size_t maxlen, int delim) {
  for (size_t i = 0; i < maxlen; ++i) {
    if (input[i] == delim) {
      return i;
    }
  }
}
 
int main(int argc, char **argv) {
  size_t i;
  int data[] = { 1, 1, 1 };
 
  i = getlen(data, sizeof(data), 0);
  printf("Returned: %zu\n", i);
  data[i] = 0;
  return 0;
}