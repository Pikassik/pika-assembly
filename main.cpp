#include <cstdio>
#include <iostream>
#include <cstring>
#include <PikaCompiler.h>

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cout << "usage: <in> <out>" << std::endl;
    std::terminate();
  }
  PikaCompiler compiler;
  compiler.SetSource(argv[1]);
  compiler.SetExecutable(argv[2]);
  compiler.Compile();
  compiler.WriteBinary();
  PikaExecutor executor;
  executor.ReadBinary(argv[2]);
  executor.Execute();
  return 0;
}

