#include<stdlib.h>

struct Node {
	int val;
	Node* next;
};

/*In this noncompliant code example, inadequate space is allocated for a struct Node object because the size of the pointer is being used to determine the size of the pointed-to object*/
Node* func1(int val) {
	Node* n;
	n = malloc(sizeof(n));
	if(n == NULL) {
		return NULL;
	}
	else {
		n->val = val;
		n->next = NULL;
	}
	return n;
}

/*In this noncompliant code example, an array of long is allocated and assigned to p. The code attempts to check for unsigned integer overflow. However, because sizeof(int) is used to compute the size, and not sizeof(long), an insufficient amount of memory can be allocated on implementations where sizeof(long) is larger than sizeof(int), and filling the array can cause a heap buffer overflow.
*/
void func2(size_t len) {
  long *p;
  if (len == 0 || len > SIZE_MAX / sizeof(long)) {
    /* Handle overflow */
  }
  p = (long *)malloc(len * sizeof(int));
  if (p == NULL) {
    /* Handle error */
  }
  free(p);
}

int main() {
	Node* n = func1(15);
	func2(10);
	return 0;
}