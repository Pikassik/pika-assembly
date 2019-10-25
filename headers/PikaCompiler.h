#pragma once
#include <Text.h>
#include <UnbreakableStack.hpp>

class PikaCompiler {
  PikaCompiler() = default;
  void Compile(const std::string_view& file_name,
               const std::string_view& binary_name);

};