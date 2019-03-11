#include <cstring>
  
class C {
  int i;
  
public:
  virtual void f();
   
  // ...
};
  
void f(C &c1, C &c2) {
  if (!std::memcmp(&c1, &c2, sizeof(C))) {
    // ...
  }
}

int main() {
	C c1 = new C();
	c1.i = 1;
	C c2 = new C();
	c2.i = 2;
	f(c1, c2);
	return 0;
}