#include "./dbgu.hpp"
#include "util.hpp"

extern "C" __attribute__((section(".init"), noinline)) void main() {
  dbgu::init();
  dbgu::printf("Hello World\r\n");
  for (;;) {
    dbgu::printf(R"(a: Data abort
s: Software
u: Undefined instruction
)");
    auto c = dbgu::read();
    switch (c) {
    case 'a':
      volatile_write(0xdeadbeef, 0x1337);
      break;
    case 'u':
      __asm__ volatile("UDF #0");
      break;
    case 's':
      __asm__ volatile("SVC #0");
      break;
    default:
      continue;
    }
  }
}
