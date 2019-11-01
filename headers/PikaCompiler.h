#pragma once
#include <Text.h>
#include <cstring>
#include <unordered_map>
#include <Instructions.h>


class PikaCompiler {
 public:
  PikaCompiler() = default;
  PikaCompiler(const PikaCompiler&) = delete;
  void SetSource(const std::string& source);
  void SetExecutable(const std::string& executable);
  void Compile();
  void WriteBinary();

 private:

  std::string source_name_;
  std::string executable_name_ = "a.out";
  std::unordered_map<std::string_view, size_t> labels_;
  text::Text source_;
  std::vector<Instruction> instructions_;
};



//#define INSTRUCTION(a, b) {\
///* some code*/\
//}
//
//for (size_t i = 0; i < n; ++i) {
//#include <Instructions.h>
//}