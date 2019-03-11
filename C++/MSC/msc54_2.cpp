/*
In this noncompliant code example, a signal handler calls a function that allows exceptions, and it attempts to handle any exceptions thrown. Because exceptions are not part of the common subset of C and C++ features, this example results in implementation-defined behavior. However, it is unlikely that the implementation's behavior will be suitable. For instance, on a stack-based architecture where a signal is generated asynchronously (instead of as a result of a call to std:abort() or std::raise()), it is possible that the stack frame is not properly initialized, causing stack tracing to be unreliable and preventing the exception from being caught properly.
*/

#include <csignal>
 
static void g() noexcept(false);
 
extern "C" void sig_handler(int sig) {
  try {
    g();
  } catch (...) {
    // Handle error
  }
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