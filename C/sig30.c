#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/*In this noncompliant example, the C standard library functions fputs() and free() are called from the signal handler via the function log_message(). Neither function is asynchronous-safe.*/
 
enum { MAXLINE = 1024 };
char *info = NULL;
 
void log_message(void) {
  fputs(info, stderr);
}
 
void handler(int signum) {
  log_message();
  free(info);
  info = NULL;
}
 
void func1(void) {
  if (signal(SIGINT, handler) == SIG_ERR) {
    /* Handle error */
  }
  info = (char *)malloc(MAXLINE);
  if (info == NULL) {
    /* Handle Error */
  }
 
  while (1) {
    /* Main loop program code */
 
    log_message();
 
    /* More program code */
  }
  return 0;
}

/*Invoking the longjmp() function from within a signal handler can lead to undefined behavior if it results in the invocation of any non-asynchronous-safe functions. Consequently, neither longjmp() nor the POSIX siglongjmp() functions should ever be called from within a signal handler.*/
void term_handler(int signum) {
  /* SIGTERM handler */
}
  
void int_handler(int signum) {
  /* SIGINT handler */
  if (raise(SIGTERM) != 0) {
    /* Handle error */
  }
}
  
void func2(void) {
  if (signal(SIGTERM, term_handler) == SIG_ERR) {
    /* Handle error */
  }
  if (signal(SIGINT, int_handler) == SIG_ERR) {
    /* Handle error */
  }
  
  /* Program code */
  if (raise(SIGINT) != 0) {
    /* Handle error */
  }
  /* More code */
  
  return EXIT_SUCCESS;
}

int main() {
  func1();
  func2();
}
