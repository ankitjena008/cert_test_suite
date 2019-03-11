/*
In this noncompliant code example, iterators from different containers are passed for the same iterator range. Although many STL implementations will compile this code and the program may behave as the developer expects, there is no requirement that an STL implementation treat a default-initialized iterator as a synonym for the iterator returned by end().
*/

#include <algorithm>
#include <iostream>
#include <vector>
  
void f(const std::vector<int> &c) {
  std::vector<int>::const_iterator e;
  std::for_each(c.begin(), e, [](int i) { std::cout << i; });
}

int main() {
	vector<int> v = {1,2,3,4,5};
	f(v);
	return 0;
}