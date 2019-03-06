#include <signal.h>
#include <stdlib.h>
#include <string.h>

/*In this noncompliant code example, err_msg is updated to indicate that the SIGINT signal was delivered.  The err_msg variable is a character pointer and not a variable of type volatile sig_atomic_t.
*/
 
enum { MAX_MSG_SIZE = 24 };
char *err_msg;
 
void handler(int signum) {
  strcpy(err_msg, "SIGINT encountered.");
}
 
int main(void) {
  signal(SIGINT, handler);
 
  err_msg = (char *)malloc(MAX_MSG_SIZE);
  if (err_msg == NULL) {
    /* Handle error */
  }
  strcpy(err_msg, "No errors yet.");
  /* Main code loop */
  return 0;
}