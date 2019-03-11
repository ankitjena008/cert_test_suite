/*
In this noncompliant code example, a std::vector is used in place of a pointer and size pair. The function performs a range check to ensure that pos does not exceed the upper bound of the container. Because pos is declared as a (signed) long long, this parameter can assume a negative value. On systems where std::vector::size_type is ultimately implemented as an unsigned int (such as with Microsoft Visual Studio 2013), the usual arithmetic conversions applied for the comparison expression will convert the unsigned value to a signed value. If pos has a negative value, this comparison will not fail, resulting in a write outside the bounds of the std::vector object when the negative value is interpreted as a large unsigned value in the indexing operator.
*/

#include <cstddef>
  
void insert_in_table(int *table, std::size_t tableSize, long long pos, int value) {
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