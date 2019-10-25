#include <cstdio>


void foo() {
  printf("foo");
}

#define TUPADEF(func) {\
  func();\
}

int main() {
  TUPADEF(foo)
}

