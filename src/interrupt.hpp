#pragma once

#include <stdint.h>

namespace interrupt {
// ARM.pdf page 160
constexpr int32_t BRANCH_INSTRUCTION_OP_CODE = 0xEA000000;
extern "C" void init_interrupts();
void data_abort();
void software();
void undefined_instruction();
} // namespace interrupt
