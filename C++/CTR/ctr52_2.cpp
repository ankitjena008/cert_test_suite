/*
In this noncompliant code example, std::fill_n() is used to fill a buffer with 10 instances of the value 0x42. However, the buffer has not allocated any space for the elements, so this operation results in a buffer overflow.
*/
#include <algorithm>
#include <vector>
 
void f() {
  std::vector<int> v;
  std::fill_n(v.begin(), 10, 0x42);
}

int main(int argc, char const *argv[])
{
	f();
	return 0;
}