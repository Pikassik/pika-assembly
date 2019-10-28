#include <PikaCompiler.h>
#include <Instructions.h>

#undef INSTRUCTION

#define INSTRUCTION(instruction_name, opcode, func) {\
  if (!strcmp(instruction_name, current_instruction_name)) func\
}


void PikaCompiler::SetSource(const std::string& source) {
  source_name_ = source;
  source_.ReadText(source);
}

void PikaCompiler::SetExecutable(const std::string& executable) {
  executable_name_ = executable;
}


void PikaCompiler::Compile() {
  if (source_name_.empty()) {
    std::printf("sources required\n");
    return;
  }

  for (size_t i = 0, j = 0; i < source_.Size(); ++i) {
    if (source_.At(i)[source_.At(i).size() - 1] == ':') {
      labels_[source_.At(i)] = j;
    } else {
      ++j;
    }
  }

  for (size_t i = 0; i < source_.Size(); ++i) {
    if (source_.At(i)[source_.At(i).size() - 1] == ':') {
      continue;
    }

    char* non_constant_string = const_cast<char*>(source_.At(i).data());
    char* current_instruction_name = strtok(non_constant_string, " ");
    Instruction current_instruction = {0, 0};

    #include <CompileInstructions.h>

    instructions_.push_back(current_instruction);
  }
}

void PikaCompiler::WriteBinary() {
  FILE* binary = std::fopen(executable_name_.c_str(), "w");
  std::fwrite(instructions_.data(),
              sizeof(Instruction),
              instructions_.size(),
              binary);
  fclose(binary);
}

#undef INSTRUCTION