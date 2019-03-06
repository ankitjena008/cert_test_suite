#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern void do_work(int *array, size_t size);

enum { N1 = 4096 };

/*
In this noncompliant code example, a variable length array of size size is declared. However, the value of size may be zero or excessive, potentially giving rise to a security vulnerability.
*/
void func1(size_t size) {
  int vla[size];
  do_work(vla, size);
}

/*
The following noncompliant code example defines A to be a variable length array and then uses the sizeof operator to compute its size at runtime. When the function is called with an argument greater 
than SIZE_MAX / (N1 * sizeof (int)), the runtime sizeof expression may wrap around, yielding a result that is smaller than the mathematical product N1 * n2 * sizeof (int). The call to malloc(), when 
successful, will then allocate storage for fewer than n2 elements of the array, causing one or more of the final memset() calls in the for loop to write past the end of that storage.
*/
void *func(size_t n2) {
  typedef int A[n2][N1];
 
  A *array = malloc(sizeof(A));
  if (!array) {
    /* Handle error */
    return NULL;
  }
 
  for (size_t i = 0; i != n2; ++i) {
    memset(array[i], 0, N1 * sizeof(int));
  }
 
  return array;
}



int main() 
{
	return 0;
}

