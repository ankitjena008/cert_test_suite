#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define BUFFER_SIZE 1024
  
/*
The loop copies data from src to dest. However, because the loop does not account for the null-termination character, 
it may be incorrectly written 1 byte past the end of dest.
*/
void copy(size_t n, char src[n], char dest[n]) {
   size_t i;
  
   for (i = 0; src[i] && (i < n); ++i) {
     dest[i] = src[i];
   }
   dest[i] = '\0';
}

/*
This noncompliant code example assumes that gets() will not read more than BUFFER_SIZE - 1 characters from stdin. This is 
an invalid assumption, and the resulting operation can result in a buffer overflow. The gets() function reads characters 
from the stdin into a destination array until end-of-file is encountered or a newline character is read. Any newline character 
is discarded, and a null character is written immediately after the last character read into the array.
*/
void func(void) {
  char buf[BUFFER_SIZE];
  if (gets(buf) == NULL) {
    printf("gets() error\n");
  }
}

/*
Environment variables can be arbitrarily large, and copying them into fixed-length arrays without first determining the size and 
allocating adequate storage can result in a buffer overflow.
*/
void func1(void) {
  char buff[256];
  char *editor = getenv("EDITOR");
  if (editor == NULL) {
    /* EDITOR environment variable not set */
  } else {
    strcpy(buff, editor);
  }
}

/*Similar to the noncompliant code example that invokes gets(), there are no guarantees that this code will not result in a buffer overflow.*/
enum { BUFFERSIZE = 32 };
  
void func2(void) {
  char buf[BUFFERSIZE];
  char *p;
  int ch;
  p = buf;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    *p++ = (char)ch;
  }
  *p++ = 0;
  if (ch == EOF) {
      /* Handle EOF or error */
  }
}

/*In this noncompliant example, the call to fscanf() can result in a write outside the character array buf*/
enum { BUF_LENGTH = 1024 };
  
void get_data(void) {
  char buf[BUF_LENGTH];
  if (1 != fscanf(stdin, "%s", buf)) {
    /* Handle error */
  }
 
  /* Rest of function */
}

void func3(int argc, char* argv[]) {
  const char *const name = (argc && argv[0]) ? argv[0] : "";
  char prog_name[128];
  strcpy(prog_name, name);
}

void func4(const char *name) {
  char filename[128];
  sprintf(filename, "%s.txt", name);
}


int main(int argc, char* argv[]) {
  char name[5] = "harry";
  char name_2[5];
  copy(5, name, name_2);
  func();
  func1();
  func2();
  func3(argc, argv);
  func4(name);
  get_data();
  return 0;
}


