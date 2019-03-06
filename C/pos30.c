#include <stdio.h>
#include <stdlib.h>

/*If len is equal to sizeof(buf), the null terminator is written 1 byte past the end of bu*/
void func() {
	char buf[1024];
	ssize_t len = readlink("/usr/bin/perl", buf, sizeof(buf));
	buf[len] = '\0';
}

int main() {
	func();
	return 0;
}