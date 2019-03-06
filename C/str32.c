#include <stdio.h>
#include <string.h>
#include <wchar.h>

enum { STR_SIZE = 32 };

/*
This code example is noncompliant because the character sequence c_str will not be null-terminated when passed as an argument to printf().
*/

void func(void) {
  char c_str[3] = "abc";
  printf("%s\n", c_str);
}

/*
In the following noncompliant code example, if no null character is contained in the first n characters of the source array, the result will 
not be null-terminated. Passing a non-null-terminated character sequence to strlen() is undefined behavior.
*/
size_t func1(const char *source) {
  char c_str[STR_SIZE];
  size_t ret = 0;
 
  if (source) {
    c_str[sizeof(c_str) - 1] = '\0';
    strncpy(c_str, source, sizeof(c_str));
    ret = strlen(c_str);
  } else {
    /* Handle null pointer */
    printf("Null pointer error.\n");
  }
  return ret;
}

/*This code example is noncompliant because the wide character sequence cur_msg will not be null-terminated when passed to wcslen(). This will occur if lessen_memory_usage() is invoked while cur_msg_size still has its initial value of 1024*/
wchar_t *cur_msg = NULL;
size_t cur_msg_size = 1024;
size_t cur_msg_len = 0;

void lessen_memory_usage(void) {
  wchar_t *temp;
  size_t temp_size;
 
  /* ... */
 
  if (cur_msg != NULL) {
    temp_size = cur_msg_size / 2 + 1;
    temp = realloc(cur_msg, temp_size * sizeof(wchar_t));
    /* temp &and cur_msg may no longer be null-terminated */
    if (temp == NULL) {
      /* Handle error */
    }
 
    cur_msg = temp;
    cur_msg_size = temp_size;
    cur_msg_len = wcslen(cur_msg);
  }
}

int main()
{
	func();
	char* str = "hello";
	func1(str);
	return 0;
}



