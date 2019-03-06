#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

/*The function accepts the name of the user as a string referenced by user. This is an exemplar of untrusted data that originates from an unauthenticated user.*/  
void incorrect_password_1(const char *user) {
  int ret;
  /* User names are restricted to 256 or fewer characters */
  static const char msg_format[] = "%s cannot be authenticated.\n";
  size_t len = strlen(user) + sizeof(msg_format);
  char *msg = (char *)malloc(len);
  if (msg == NULL) {
    /* Handle error */
  }
  ret = snprintf(msg, len, msg_format, user);
  if (ret < 0) { 
    /* Handle error */ 
  } else if (ret >= len) { 
    /* Handle truncated output */ 
  }
  fprintf(stderr, msg);
  free(msg);
}

/*This noncompliant code example is similar to the first noncompliant code example but uses the POSIX function syslog() which is also susceptible to format string vulnerabilities.*/
void incorrect_password_2(const char *user) {
  int ret;
  /* User names are restricted to 256 or fewer characters */
  static const char msg_format[] = "%s cannot be authenticated.\n";
  size_t len = strlen(user) + sizeof(msg_format);
  char *msg = (char *)malloc(len);
  if (msg == NULL) {
    /* Handle error */
  }
  ret = snprintf(msg, len, msg_format, user);
  if (ret < 0) { 
    /* Handle error */ 
  } else if (ret >= len) { 
    /* Handle truncated output */ 
  }
  syslog(LOG_INFO, msg);
  free(msg);
}

int main() {
  char* username = "joker";
  incorrect_password_1(username);
  incorrect_password_2(username);
  return 0;
}