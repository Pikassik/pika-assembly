#include <cstdio>
#include <iostream>
#include <cstring>
#include <PikaCompiler.h>

int main() {
  PikaCompiler compiler;
  compiler.SetSource("../solve_square");
  compiler.SetExecutable("../output");
  compiler.Compile();
  compiler.WriteBinary();
  PikaExecutor executor;
  executor.ReadBinary("../output");
  executor.Execute();
  return 0;
}

