#include <PikaExecutor.h>


void PikaExecutor::ReadBinary(const std::string& file_name) {
  instructions_.clear();
  fclose(state_.binary);
  FILE* binary = fopen(file_name.c_str(), "r");
  assert(binary != nullptr);
  uint32_t instructions_count = 0;
  fread(&instructions_count, sizeof(instructions_count), 1, binary);
  instructions_.resize(instructions_count);
  std::fread(instructions_.data(),
             sizeof(Instruction),
             instructions_.size(),
             binary);
  state_.binary = binary;
}

size_t PikaExecutor::GetInstructionsCount(std::FILE* file) {
  assert(file != nullptr);
  std::fseek(file, 0, SEEK_END);
  size_t instructions_count = std::ftell(file) / sizeof(Instruction);
  std::fseek(file, 0, SEEK_SET);
  return instructions_count;
}

void PikaExecutor::Execute() {
  while (state_.program_counter < instructions_.size() &&
         Opcode(instructions_[state_.program_counter]) != 0xFF) {
    Instruction instr = instructions_[state_.program_counter];
    switch (Opcode(instr)) {
    #include <ExecuteInstructions.h>
      default: assert(false);
    }
    ++state_.program_counter;
  }
}

std::string GetStringFromBinary(FILE* binary, uint32_t offset, uint32_t size) {
  std::string out(size, 'o');
  long before = std::ftell(binary);
  std::fseek(binary, offset, SEEK_CUR);
  std::fread(out.data(), sizeof(char), size, binary);
  std::fseek(binary, before, SEEK_SET);
  return out;
}

PikaExecutor::~PikaExecutor() {
  fclose(state_.binary);
}