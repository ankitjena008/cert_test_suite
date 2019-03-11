/*
In this noncompliant code example, the complete object representation is accessed when comparing two objects of type S. Per the C++ Standard, [class], paragraph 13 [ISO/IEC 14882-2014], classes may be padded with data to ensure that they are properly aligned in memory. The contents of the padding and the amount of padding added is implementation-defined. This can lead to incorrect results when comparing the object representation of classes instead of the value representation, as the padding may assume different unspecified values for each object instance.
*/
#include <cstring>
  
struct S {
  unsigned char buffType;
  int size;
};
  
void f(const S &s1, const S &s2) {
  if (!std::memcmp(&s1, &s2, sizeof(S))) {
    // ...
  }
}

int main() {
	S s1 = new S();
	s1.buffType = 'a';
	s1.size = 10;
	S s2 = new S();
	s2.buffType = 'b';
	s2.size = 20;
	return 0;
}