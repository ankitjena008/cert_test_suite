#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define COLS 5
#define ROWS 7
  
struct S {
  size_t len;
  char buf[];  /* Flexible array member */
};


/*
In this noncompliant code example, the function f() attempts to validate the index before using it as an offset to the statically allocated table of integers. However, the function fails to reject negative index values. When index is less than zero, the behavior of the addition expression in the return statement of the function is undefined behavior 46. On some implementations, the addition alone can trigger a hardware trap. On other implementations, the addition may produce a result that when dereferenced triggers a hardware trap. Other implementations still may produce a dereferenceable pointer that points to an object distinct from table. Using such a pointer to access the object may lead to information exposure or cause the wrong object to be modified.
*/

enum { TABLESIZE = 100 };
 
static int table[TABLESIZE];
 
int *f(int index) {
  if (index < TABLESIZE) {
    return table + index;
  }
  return NULL;
}

/*
This noncompliant code example declares matrix to consist of 7 rows and 5 columns in row-major order. 
The function init_matrix iterates over all 35 elements in an attempt to initialize each to the value given by the function argument x. 
However, because multidimensional arrays are declared in C in row-major order, the function iterates over the elements in column-major order, 
and when the value of j reaches the value COLS during the first iteration of the outer loop, the function attempts to access element matrix[0][5]. 
Because the type of matrix is int[7][5], the j subscript is out of range, and the access has undefined behavior 49.
*/
static int matrix[ROWS][COLS];
 
void init_matrix(int x) {
  for (size_t i = 0; i < COLS; i++) {
    for (size_t j = 0; j < ROWS; j++) {
      matrix[i][j] = x;
    }
  }
}


/*
In this noncompliant code example, the function find() attempts to iterate over the elements of the flexible array member buf, starting with the second element. 
However, because function g() does not allocate any storage for the member, the expression first++ in find() attempts to form a pointer just past the end of buf 
when there are no elements.
*/
const char *find(const struct S *s, int c) {
  const char *first = s->buf;
  const char *last  = s->buf + s->len;
 
  while (first++ != last) { /* Undefined behavior */
    if (*first == (unsigned char)c) {
      return first;
    }
  }
  return NULL;
}
  
void g(void) {
  struct S *s = (struct S *)malloc(sizeof(struct S));
  if (s == NULL) {
    /* Handle error */
  }
  s->len = 0;
  find(s, 'a');
}

/*
This code allocates a block of memory and initializes it with some data. The data does not belong at the beginning of the block, 
which is left uninitialized. Instead, it is placed offset bytes within the block. The function ensures that the data fits within the allocated block. 
*/

char *init_block(size_t block_size, size_t offset,
                 char *data, size_t data_size) {
  char *buffer = malloc(block_size);
  if (data_size > block_size || block_size - data_size < offset) {
    /* Data won't fit in buffer, handle error */
  }
  memcpy(buffer + offset, data, data_size);
  return buffer;
}

/*the function insert_in_table() in this noncompliant code example uses an otherwise valid index to attempt to store a value in an element just past the end of an array.*/
static int *table_1 = NULL;
static size_t size_1 = 0;
 
int insert_in_table(size_t pos, int value) {
  if (size_1 < pos) {
    int *tmp;
    size_1 = pos + 1;
    tmp = (int *)realloc(table_1, sizeof(*table_1) * size_1);
    if (tmp == NULL) {
      return -1;   /* Failure */
    }
    table_1 = tmp;
  }
 
  table_1[pos] = value;
  return 0;
}



int main() {
	int *temp = f(-1);
	init_matrix(1);
	g();
	char* temp_1 = "hello";
	char* res = init_block(10, 2, temp, 5);
	int temp1 = insert_in_table(0, 0);
	return 0;
}


