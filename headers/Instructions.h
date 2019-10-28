#pragma once
#include <cstdint>
#include <string_view>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

struct Instruction {
  uint32_t instruction;
  uint32_t value;
};

uint32_t RegisterToInt(const char* register_name);
