#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>  

/*This noncompliant code example incorrectly uses the strncpy() function in an attempt to copy up to 10 wide characters. However, because wide characters can contain null bytes, the copy operation may end earlier than anticipated, resulting in the truncation of the wide string.*/
void func1(void) {
  wchar_t wide_str1[]  = L"0123456789";
  wchar_t wide_str2[] =  L"0000000000";
 
  strncpy(wide_str2, wide_str1, 10);
}

/*This noncompliant code example incorrectly invokes the wcsncpy() function to copy up to 10 wide characters from narrow_str1 to narrow_str2. Because narrow_str2 is a narrow string, it has insufficient memory to store the result of the copy and the copy will result in a buffer overflow.*/
void func2(void) {
  char narrow_str1[] = "01234567890123456789";
  char narrow_str2[] = "0000000000";
 
  wcsncpy(narrow_str2, narrow_str1, 10);
}

/*In this noncompliant code example, the strlen() function is used to determine the size of a wide character string:
*/
void func3(void) {
  wchar_t wide_str1[] = L"0123456789";
  wchar_t *wide_str2 = (wchar_t*)malloc(strlen(wide_str1) + 1);
  if (wide_str2 == NULL) {
    /* Handle error */
  }
  /* ... */
  free(wide_str2);
  wide_str2 = NULL;
}

int main() {
	func1();
	func2();
	func3();
	return 0;
}