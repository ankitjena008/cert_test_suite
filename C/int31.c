/*
Type range errors, including loss of data (truncation) and loss of sign (sign errors), can occur 
when converting from a value of an unsigned integer type to a value of a signed integer type. 
This noncompliant code example results in a truncation error on most implementations:
*/

#include<limits.h>
#include<sys/time.h>
#include<string.h>
#include<stddef.h>
#include<stdio.h>
  
void func(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  sc = (signed char)u_a; /* Cast eliminates warning */
  /* ... */
}

/*
Type range errors, including loss of data (truncation) and loss of sign (sign errors), 
can occur when converting from a value of a signed type to a value of an unsigned type. This noncompliant code example results in a loss of sign:
*/
void func1(void) {
  signed int si = INT_MIN;
  /* Cast eliminates warning */
  unsigned int ui = (unsigned int)si;
 
  /* ... */
}

/*
A loss of data (truncation) can occur when converting from a value of a signed 
integer type to a value of a signed type with less precision. 
This noncompliant code example results in a truncation error on most implementations:
*/
void func2(void) {
  signed long int s_a = LONG_MAX;
  signed char sc = (signed char)s_a; /* Cast eliminates warning */
  /* ... */
}


/*
The time() function returns the value (time_t)(-1) to indicate that the calendar time is not available. 
The C Standard requires that the time_t type is only a real type capable of representing time. 
(The integer and real floating types are collectively called real types.) It is left to the implementor to decide the best 
real type to use to represent time. If time_t is implemented as an unsigned integer type with less precision than a signed int, the return value of time() 
will never compare equal to the integer literal -1.
*/

void func3(void) {
  time_t now = time(NULL);
  if (now != -1) {
    /* Continue processing */
    printf("Some processing here\n");
  }
}

/*
For historical reasons, certain C Standard functions accept an argument of type int and convert it to either unsigned char or plain char. 
This conversion can result in unexpected behavior if the value cannot be represented in the smaller type. This noncompliant solution unexpectedly clears the array:
*/
int *init_memory(int *array, size_t n) {
  return memset(array, 4096, n); 
} 

void func4(void) {
  unsigned long int u_a = ULONG_MAX;
  unsigned char uc = (unsigned char)u_a; /* Cast eliminates warning */
  /* ... */
}



int main() {
	func();
	func1();
	func2();
	func3();
	int n = 10;
	int *arr = malloc(n * sizeof(int));
	int* temp = init_memory(arr, n);
	return 0;
}

