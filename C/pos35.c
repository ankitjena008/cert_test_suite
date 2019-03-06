#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void func() {
	char *filename = "temp.txt";
	char *userbuf = "Temp";
	unsigned int userlen = 4;
 
	struct stat lstat_info;
	int fd;
	/* ... */
	if (lstat(filename, &lstat_info) == -1) {
  	/* Handle error */
	}
 
	if (!S_ISLNK(lstat_info.st_mode)) {
   		fd = open(filename, O_RDWR);
   		if (fd == -1) {
       		/* Handle error */
   		}
	}
	if (write(fd, userbuf, userlen) < userlen) {
  		/* Handle error */
	}
}

int main() {
	func();
	return 0;
}