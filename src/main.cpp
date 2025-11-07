#include "./dbgu.hpp"

extern "C" __attribute__((section(".init"), noinline)) void main() {
  dbgu::init();
  dbgu::printf("Hello World\r\n");
  for (;;) {
    char c = dbgu::read();                // Wait for the next character
    dbgu::printf("You wrote: %c\r\n", c); // Print the received character
  }
  for (;;)
    ;
}
