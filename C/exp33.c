#include<stdio.h>
#include <wchar.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
/*
In this noncompliant code example, the set_flag() function is intended to set the parameter, sign_flag, to the sign of number. 
However, the programmer neglected to account for the case where number is equal to 0. 
Because the local variable sign is uninitialized when calling set_flag() and is never written to by set_flag(), 
the comparison operation exhibits undefined behavior when reading sign.
*/

void set_flag(int number, int *sign_flag) {
  if (sign_flag == NULL) {
    return;
  }
 
  if (number > 0) {
    *sign_flag = 1;
  } else if (number < 0) {
    *sign_flag = -1;
  }
}

void func(const char *mbs) {
  size_t len;
  mbstate_t state;
 
  len = mbrlen(mbs, strlen(mbs), &state);
}

void func1(void) {
  struct timeval tv;
  unsigned long junk;
 
  gettimeofday(&tv, NULL);
  srandom((getpid() << 16) ^ tv.tv_sec ^ tv.tv_usec ^ junk);
}
 
int is_negative(int number) {
  int sign;
  set_flag(number, &sign);
  return sign < 0;
}

extern int do_auth(void);
enum { BUFFERSIZE = 24 }; 
void report_error(const char *msg) {
  const char *error_log;
  char buffer[BUFFERSIZE];
 
  sprintf(buffer, "Error: %s", error_log);
  printf("%s\n", buffer);
}

enum { OLD_SIZE = 10, NEW_SIZE = 20 };
int *resize_array(int *array, size_t count) {
  if (0 == count) {
    return 0;
  }
  
  int *ret = (int *)realloc(array, count * sizeof(int));
  if (!ret) {
    free(array);
    return 0;
  }
  
  return ret;
}

void func2(void) {
  
  int *array = (int *)malloc(OLD_SIZE * sizeof(int));
  if (0 == array) {
    /* Handle error */
  }
  
  for (size_t i = 0; i < OLD_SIZE; ++i) {
    array[i] = i;
  }
  
  array = resize_array(array, NEW_SIZE);
  if (0 == array) {
    /* Handle error */
  }
  
  for (size_t i = 0; i < NEW_SIZE; ++i) {
    printf("%d ", array[i]);
  }
}

int main()
{
  is_negative(-9);
  const char* sample_msg = "Happy birthday";
  func1();
  func(sample_msg);
  if(do_auth() == -1)
    report_error("Unable to login");
  func2();
  return 0;
}