#pragma once
#include <cstdint>
#include <string_view>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <PikaExecutor.h>
#include <cmath>

struct Instruction {
  uint32_t instruction;
  uint32_t value;
};

uint32_t RegisterToInt(const char* register_name);
uint32_t Opcode(const Instruction& instr);
