#include <time.h>

/*This noncompliant code example invokes the asctime() function with potentially unsanitized data*/
void func(struct tm *time_tm) {
  char *time = asctime(time_tm);
  /* ... */
}

int main() {
	time_t rawtime;
  	struct tm * timeinfo;
  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
  	func(timeinfo);
  	return 0;
}

