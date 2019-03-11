/*
In this noncompliant code example, the class C is given ownership of a P *, which is subsequently deleted by the class destructor.Despite the presence of a user-declared destructor, C will have an implicitly defaulted copy constructor defined for it, and this defaulted copy constructor will copy the pointer value stored in p, resulting in a double-free: the first free happens when g() exits and the second free happens when h() exits.
*/

struct P {};
 
class C {
  P *p;
   
public:
  C(P *p) : p(p) {}
  ~C() { delete p; } 
   
  void f() {}
};
 
void g(C c) {
  c.f();
}
 
void h() {
  P *p = new P;
  C c(p);
  g(c);
}

int main() {
	h();
	return 0;
}