#include<stdio.h>
/*
This noncompliant code example can result in an unsigned integer wrap during the addition of the unsigned operands ui_a and ui_b. 
If this behavior is unexpected, the resulting value may be used to allocate insufficient memory for a subsequent operation or in some 
other manner that can lead to an exploitable vulnerability.
*/

void func1(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = ui_a + ui_b;
}

void func2(unsigned int ui_a, unsigned int ui_b) {
  unsigned int udiff = ui_a - ui_b;
}

void func3(signed int ui_a, size_t ui_b) {
  unsigned int uprod = ui_a * ui_b;
}

int main(int argc, char const *argv[])
{
	func(3,5);
	return 0;
}