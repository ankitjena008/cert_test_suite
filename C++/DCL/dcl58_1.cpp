/*
In this noncompliant code example, the declaration of x is added to the namespace std, resulting in undefined behavior.
*/

namespace std {
int x;
}

#include<iostream>
using namespace std;

int main() {
	cout << "Hello World\n";
	return 0;
}