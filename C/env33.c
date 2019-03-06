#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
/*In this noncompliant code example, the system() function is used to execute any_cmd in the host environment. Invocation of a command processor is not required.*/

enum { BUFFERSIZE = 512 };
 
void func1(const char *input) {
  char cmdbuf[BUFFERSIZE];
  int len_wanted = snprintf(cmdbuf, BUFFERSIZE,
                            "any_cmd '%s'", input);
  if (len_wanted >= BUFFERSIZE) {
    /* Handle error */
  } else if (len_wanted < 0) {
    /* Handle error */
  } else if (system(cmdbuf) == -1) {
    /* Handle error */
  }
}

/*This noncompliant code invokes the C system() function to remove the .config file in the user's home directory.*/
void func2(void) {
  system("rm ~/.config");
}