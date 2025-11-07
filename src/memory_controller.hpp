#pragma once
#include "util.hpp"
#include <stdint.h>

namespace memory_controller {
constexpr uint32_t REMAP_CONTROL_REGISTER = 0xFFFFFF00;
constexpr uint32_t REMAP_COMMAND_BIT = 1 << 0;
inline void remap() {
  volatile_write(REMAP_CONTROL_REGISTER, REMAP_COMMAND_BIT);
}
} // namespace memory_controller
