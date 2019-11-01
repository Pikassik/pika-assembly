#include <PikaExecutor.h>


void PikaExecutor::ReadBinary(const std::string& file_name) {
  instructions_.clear();
  FILE* binary = fopen(file_name.c_str(), "r");
  assert(binary != nullptr);
  instructions_.resize(GetInstructionsCount(binary));
  std::fread(instructions_.data(),
             sizeof(Instruction),
             instructions_.size(),
             binary);
  fclose(binary);
}

size_t PikaExecutor::GetInstructionsCount(std::FILE* file) {
  assert(file != nullptr);
  std::fseek(file, 0, SEEK_END);
  size_t instructions_count = std::ftell(file) / sizeof(Instruction);
  std::fseek(file, 0, SEEK_SET);
  return instructions_count;
}

void PikaExecutor::Execute() {
  while (state_.program_counter < instructions_.size()) {
    Instruction instr = instructions_[state_.program_counter];
    switch (Opcode(instr)) {
    #include <ExecuteInstructions.h>
      default: assert(false);
    }
    ++state_.program_counter;
  }
}

