/*
In this noncompliant code example, a pointer to an object of nonstandard-layout type is passed to a function that has a "Fortran" language linkage. Language linkages other than "C" and "C++" are conditionally supported with implementation-defined semantics [ISO/IEC 14882-2014]. If the implementation does not support this language linkage, the code is ill-formed. Assuming that the language linkage is supported, any operations performed on the object passed may result in indeterminate behavior, which could have security implications.
*/

struct B {
  int i, j;
};
  
struct D : B {
  float f;
};
  
extern "Fortran" void func(void *);
  
void foo(D *d) {
  func(d);
}

int main() {
	D* temp = new D();
	temp->i = 0;
	temp->j = 1;
	temp->f = 2.5;
	foo(temp)
	return 0;
}