#pragma once
#include <cstdint>
#include <array>
#include <vector>
#include <GeneratedInstructions.h>
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
  union StackValue {
    uint32_t int_v;
    float float_v;
    explicit StackValue(const float& float_v) : float_v(float_v) {};
    explicit StackValue(const uint32_t& int_v) : int_v(int_v) {};
  };
  UnbreakableStack<StackValue, Static, DefaultDump<StackValue>, kStackSize> stack;
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