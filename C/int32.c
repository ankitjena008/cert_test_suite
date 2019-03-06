#include <limits.h>
#include <stddef.h>
#include <inttypes.h>

/*
This noncompliant code example can result in a signed integer overflow during the addition of the signed operands si_a and si_b:
*/
void func(signed int si_a, signed int si_b) {
  signed int sum = si_a + si_b;
  printf("Sum = %d", sum);
}

void func_diff(signed int si_a, signed int si_b) {
  signed int diff = si_a - si_b;
  printf("Diff = %d", diff);
}

void func_prod(signed int si_a, signed int si_b) {
  signed int prod = si_a + si_b;
  printf("Product = %d", prod);
}

/*
This noncompliant code example prevents divide-by-zero errors in compliance with  INT33-C. 
Ensure that division and remainder operations do not result in divide-by-zero errors but does not prevent a signed integer overflow error in two's-complement. 
*/
void func1(signed long s_a, signed long s_b) {
  signed long result;
  if (s_b == 0) {
    printf("Oops error 1\n");
  } else {
    result = s_a / s_b;
    printf("Division result = %l\n", result);
  }
}


/*
Many hardware architectures implement remainder as part of the division operator, which can overflow. Overflow can occur during a 
remainder operation when the dividend is equal to the minimum (negative) value for the signed integer type and the divisor is equal to −1. 
It occurs even though the result of such a remainder operation is mathematically 0. This noncompliant code example prevents 
divide-by-zero errors in compliance with INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors 
but does not prevent integer overflow:
*/
void func2(signed long s_a, signed long s_b) {
  signed long result;
  if (s_b == 0) {
    printf("Oops error 2\n");
  } else {
    result = s_a % s_b;
    printf("Mod result = %l\n", result);
  }
  /* ... */
}

/*
This noncompliant code example performs a left shift, after verifying that the number being shifted is not negative, 
and the number of bits to shift is valid.  The PRECISION() macro and popcount() function provide the correct precision for 
any integer type. (See INT35-C. Use correct integer precisions.) However, because this code does no overflow check, it can result in an unrepresentable value.
*/
extern size_t popcount(uintmax_t);
#define PRECISION(umax_value) popcount(umax_value)
 
void func3(signed long si_a, signed long si_b) {
  signed long result;
  if ((si_a < 0) || (si_b < 0) || (si_b >= PRECISION(ULONG_MAX))) {
    printf("Precision error\n");
  } else {
    result = si_a << si_b;
    printf("Leftshift result = %l\n", result);
  }
  /* ... */
}

void func_unary(signed long s_a) {
  signed long result = -s_a;
  /* ... */
}

int main() {
	signed int a = 50;
	signed int b = 10;
	signed long c = 40;
	signed long d = 3;
	func(a, b);
  func_prod(a, b);
  func_diff(a, b);
	func1(c, d);
	func2(c, d);
	func3(c, d);
  func_unary(a);
	return 0;
}





