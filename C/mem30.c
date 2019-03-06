#include <stdlib.h>
#include <string.h>
  
struct node {
  int value;
  struct node *next;
};
  
/*
In their (intentionally) incorrect example, p is freed before p->next is executed, so that p->next reads 
memory that has already been freed.
*/
void func1(struct node *head) {
  for (struct node *p = head; p != NULL; p = p->next) {
    free(p);
  }
}

/*
In this noncompliant code example, buf is written to after it has been freed. Write-after-free vulnerabilities can be exploited to run 
arbitrary code with the permissions of the vulnerable process.
*/
void func2(int argc, char *argv[]) {
  char *return_val = 0;
  const size_t bufsize = strlen(argv[0]) + 1;
  char *buf = (char *)malloc(bufsize);
  if (!buf) {
    return;
  }
  /* ... */
  free(buf);
  /* ... */
  strcpy(buf, argv[0]);
  /* ... */
  return;
}

/*In this noncompliant example, realloc() may free c_str1 when it returns a null pointer, resulting in c_str1 being freed twice.*/
void func3(char *c_str1, size_t size) {
  char *c_str2 = (char *)realloc(c_str1, size);
  if (c_str2 == NULL) {
    free(c_str1);
  }
}

int main(int argc, char* argv[]) {
	struct node* p = malloc(sizeof(struct node));
	p->value = 1;
	p->next = NULL;
	func1(p);
	func2(argc, argv);
  char *c = "test";
  size_t size = 4;
  func3(c, size);
	return 0;
}