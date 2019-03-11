/*
In this noncompliant code example, the constructor for the automatic variable s is not called because execution does not flow through the declaration of the local variable due to the goto statement. Because the constructor is not called, the lifetime for s has not begun. Therefore, calling S::f() uses the object outside of its lifetime and results in undefined behavior.	
*/

class S {
  int v;
  
public:
  S() : v(12) {} // Non-trivial constructor
  
  void f();
};  
  
void f() {
  
  // ...  
  
  goto bad_idea;  
  
  // ...
  
  S s; // Control passes over the declaration, so initialization does not take place.  
  
  bad_idea:
    s.f();
}

int main() {
	f();
	return 0;
}