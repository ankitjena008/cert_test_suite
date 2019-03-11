/*
In this noncompliant code example, two memory allocations are performed within the same expression. Because the memory allocations are passed as arguments to a function call, an exception thrown as a result of one of the calls to new could result in a memory leak.
*/

struct A { /* ... */ };
struct B { /* ... */ }; 
  
void g(A *, B *);
void f() {
  g(new A, new B);
}

int main() {
	f();
	return 0;
}