#pragma once
#include <cstdint>
#include <array>
#include <vector>
#undef IS_NOT_FATAL
#define IS_NOT_FATAL false

#include <UnbreakableStack.hpp>
#include <Instructions.h>

constexpr size_t kStackSize =
    static_cast<size_t>(1) << static_cast<size_t>(13);


struct ExecutorState {
  ExecutorState() = default;
  size_t program_counter = 0;
  bool ZF = false, SF = false, CF = false, OF = false;
  std::array<uint32_t, 4> integral_registers = {0, 0, 0, 0};
  std::array<float, 4> float_registers = {0.f, 0.f, 0.f, 0.f};
  UnbreakableStack<uint32_t, Static, DefaultDump<uint32_t>, kStackSize> stack;
};

class PikaExecutor {
 public:
  PikaExecutor() = default;
  void ReadBinary(const std::string& file_name);
  void Execute();
 private:
  size_t GetInstructionsCount(std::FILE* file);
  ExecutorState state_;
  std::vector<struct Instruction> instructions_;
};