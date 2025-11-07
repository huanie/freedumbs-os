#pragma once

#include <stdint.h>

namespace interrupt {
constexpr uint32_t BASE = 0xFFFFF000;
constexpr uint32_t INTERRUPT_VECTOR_REGISTER = 0x100;
constexpr uint32_t JUMP = 0xe51ff004; // ldr     pc, [pc, #-4]
} // namespace interrupt
