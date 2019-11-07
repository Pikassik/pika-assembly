#include <Instructions.h>

uint32_t RegisterToInt(const char* register_name) {
  if        (!std::strcmp(register_name, "eax") ||
             !std::strcmp(register_name, "xmm0")) {
    return 0;
  } else if (!std::strcmp(register_name, "ebx") ||
             !std::strcmp(register_name, "xmm1")) {
    return 1;
  } else if (!std::strcmp(register_name, "ecx") ||
             !std::strcmp(register_name, "xmm2")) {
    return 2;
  } else if (!std::strcmp(register_name, "edx") ||
             !std::strcmp(register_name, "xmm3")) {
    return 3;
  }

  assert(false);
}

uint32_t Opcode(const Instruction& instr) {
  return
    instr.instruction << static_cast<uint32_t>(4) >> static_cast<uint32_t>(4);
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////_INSTRUCTIONS_/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
