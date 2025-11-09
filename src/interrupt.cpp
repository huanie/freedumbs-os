#include "interrupt.hpp"
#include "dbgu.hpp"
#include "util.hpp"
#include <stdint.h>

void __attribute__((interrupt("ABORT"))) interrupt::data_abort() {
  dbgu::printf("abort!\n");
}
void __attribute__((interrupt("SWI"))) interrupt::software() {
  dbgu::printf("software!\n");
}
void __attribute__((interrupt("UNDEF"))) interrupt::undefined_instruction() {
  dbgu::printf("Undefined instruction!\n");
}

template <uint32_t target, uint32_t destination>
constexpr inline uint32_t encode_load() {
  // +8 because that's the actual current instruction of the PC
  // we want to load the contents in destination address into PC
  auto constexpr pc = target + 8;
  auto constexpr offset = destination - pc;
  static_assert(offset < 0xFFF, "The destination is out of bounds");

  return 0xE59FF000 | offset;
}

using handler_function = void (*)(void);
template <uint32_t target, uint32_t destination>
inline void install_interrupt_handler(handler_function handler) {
  volatile_write(target, encode_load<target, destination>());
  volatile_write(destination, reinterpret_cast<uint32_t>(handler));
}

constexpr uint32_t DATA_ABORT = 0x10;
constexpr uint32_t SOFTWARE = 0x8;
constexpr uint32_t UNDEFINED_INSTRUCTION = 0x4;

consteval uint32_t vector(int index) {
  // That's where the addresses of the interrupt handlers are stored
  constexpr uint32_t VECTOR = 0x30;
  return VECTOR + index * sizeof(uint32_t);
}
extern "C" void interrupt::init_interrupts() {
  // load instructions to load the handlers into PC
  install_interrupt_handler<DATA_ABORT, vector(0)>(&data_abort);
  install_interrupt_handler<SOFTWARE, vector(1)>(&software);
  install_interrupt_handler<UNDEFINED_INSTRUCTION, vector(2)>(
      &undefined_instruction);
}
