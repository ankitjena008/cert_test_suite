/*
In this noncompliant code example, the signal handler is declared as a static function. However, since all signal handler functions must have C language linkage, and C++ is the default language linkage for functions in C++, calling the signal handler results in undefined behavior.
*/

#include <csignal>
  
static void sig_handler(int sig) {
  // Implementation details elided.
}
 
void install_signal_handler() {
  if (SIG_ERR == std::signal(SIGTERM, sig_handler)) {
    // Handle error
  }
}

int main() {
	install_signal_handler();
	return 0;
}