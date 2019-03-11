/*
In this noncompliant code example, pos is invalidated after the first call to insert(), and subsequent loop iterations have undefined behavior.
*/

#include <deque>
  
void f(const double *items, std::size_t count) {
  std::deque<double> d;
  auto pos = d.begin();
  for (std::size_t i = 0; i < count; ++i, ++pos) {
    d.insert(pos, items[i] + 41.0);
  }
}

int main() {
	double d[5] = {1.0, 2.1, 3.2, 4.3, 5.4};
	int x = 5;
	size_t s = (size_t) x;
	f(d, s);
	return 0;
}