#include <cstdio>
#include <iostream>
#include <cstring>
#include <PikaCompiler.h>

int main() {
  PikaCompiler compiler;
  compiler.SetSource("input");
  compiler.SetExecutable("output");
  compiler.Compile();
  compiler.WriteBinary();
  return 0;
}

