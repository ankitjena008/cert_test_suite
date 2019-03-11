/*
This noncompliant code example shows a function, insert_in_table(), that has two int parameters, pos and value, both of which can be influenced by data originating from untrusted sources. The function performs a range check to ensure that pos does not exceed the upper bound of the array, specified by tableSize, but fails to check the lower bound. Because pos is declared as a (signed) int, this parameter can assume a negative value, resulting in a write outside the bounds of the memory referenced by table.
*/

#include <cstddef>
  
void insert_in_table(int *table, std::size_t tableSize, int pos, int value) {
  if (pos >= tableSize) {
    // Handle error
    return;
  }
  table[pos] = value;
}

int main() {
	int temp[5] = {1,2,3,4,5};
	int x = 5;
	size_t tableSize = (size_t)x;
	int pos = 1;
	int value = 3;
	insert_in_table(temp, tableSize, pos, value);
	return 0;
}