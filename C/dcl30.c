/*
In this noncompliant code example, the address of the variable c_str with automatic storage duration is assigned to the variable p, which has static storage duration. 
The assignment itself is valid, but it is invalid for c_str to go out of scope while p holds its address, as happens at the end of dont_do_this().
*/
#include <stdio.h>
  
const char *p;
void dont_do_this(void) {
  const char c_str[] = "This will change";
  p = c_str; /* Dangerous */
}

char *init_array(void) {
  char array[10];
  /* Initialize array */
  return array;
}
 
void innocuous(void) {
  printf("%s\n", p);
}

/* In this noncompliant code example, the function squirrel_away() stores a pointer to local variable local into a location pointed to by function parameter ptr_param. Upon the return of squirrel_away(), the pointer ptr_param points to a variable that has an expired lifetime.
*/
void squirrel_away(char **ptr_param) {
  char local[10];
  /* Initialize array */
  *ptr_param = local;
}
 
void rodent(void) {
  char *ptr;
  squirrel_away(&ptr);
  /* ptr is live but invalid here */
}
 
int main(void) {
  dont_do_this();
  char* temp = init_array();
  innocuous();
  rodent();
  return 0;
}