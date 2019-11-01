#include <Instructions.h>

uint32_t RegisterToInt(const char* register_name) {
  if        (!std::strcmp(register_name, "eax") ||
             !std::strcmp(register_name, "xmm0")) {
    return 0;
  } else if (!std::strcmp(register_name, "ebx") ||
             !std::strcmp(register_name, "xmm1")) {
    return 1;
  } else if (!std::strcmp(register_name, "ecx") ||
             !std::strcmp(register_name, "xmm2")) {
    return 2;
  } else if (!std::strcmp(register_name, "edx") ||
             !std::strcmp(register_name, "xmm3")) {
    return 3;
  }

  assert(false);
}

uint32_t Opcode(const Instruction& instr) {
  return
    instr.instruction << static_cast<uint32_t>(4) >> static_cast<uint32_t>(4);
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////_INSTRUCTIONS_/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void pushc(ExecutorState& state, uint32_t constant) {
  state.stack.Push(constant);
}

void pushr(struct ExecutorState& state, size_t reg0) {
  state.stack.Push(state.integral_registers[reg0]);
}

void pushfc(struct ExecutorState& state, uint32_t constant) {
  state.stack.Push(constant);
}

void pushfr(struct ExecutorState& state, size_t reg0) {
  state.stack.Push(*reinterpret_cast<uint32_t*>(&state.float_registers[reg0]));
}

void movrr(ExecutorState& state, size_t reg0, size_t reg1) {
  state.integral_registers[reg0] = state.integral_registers[reg1];
}

void movrc(ExecutorState& state, size_t reg0, uint32_t constant) {
  state.integral_registers[reg0] = constant;
}

void movfrr(struct ExecutorState& state, size_t reg0, size_t reg1) {
  state.float_registers[reg0] = state.float_registers[reg1];
}
void movfrc(struct ExecutorState& state, size_t reg0, uint32_t constant) {
  state.float_registers[reg0] = *reinterpret_cast<const float*>(&constant);
}

void popr(ExecutorState& state, size_t reg0) {
  state.integral_registers[reg0] = state.stack.Top();
  state.stack.Pop();
}

void popfr(struct ExecutorState& state, size_t reg0) {
  state.float_registers[reg0] =
    *reinterpret_cast<const float*>(&state.stack.Top());
  state.stack.Pop();
}

void addrr(ExecutorState& state, size_t reg0, size_t reg1) {
  state.integral_registers[reg0] += state.integral_registers[reg1];
}

void addfrr(struct ExecutorState& state, size_t reg0, size_t reg1) {
  state.float_registers[reg0] += state.float_registers[reg1];
}

void mulrr(ExecutorState& state, size_t reg0, size_t reg1) {
  state.integral_registers[reg0] *= state.integral_registers[reg1];
}

void mulfrr(struct ExecutorState& state, size_t reg0, size_t reg1) {
  state.float_registers[reg0] *= state.float_registers[reg1];
}

void mulfrc(struct ExecutorState& state, size_t reg0, uint32_t constant) {
  state.float_registers[reg0] *= *reinterpret_cast<float*>(&constant);
}

void inint(ExecutorState& state) {
  int32_t input;
  scanf("%d", &input);
  state.stack.Push(*(reinterpret_cast<uint32_t*>(&input)));
}

void inch(ExecutorState& state) {
  int32_t input = getchar();
  state.stack.Push(*(reinterpret_cast<uint32_t*>(&input)));
}

void inf(struct ExecutorState& state) {
  float input;
  scanf("%f", &input);
  state.stack.Push(*(reinterpret_cast<uint32_t*>(&input)));
}

void outint(ExecutorState& state) {
  printf("%d", *(reinterpret_cast<const int32_t*>(&state.stack.Top())));
}

void outch(ExecutorState& state) {
  putchar(state.stack.Top());
}

void outf(ExecutorState& state) {
  printf("%f", *(reinterpret_cast<const float*>(&state.stack.Top())));
}

void cmp(struct ExecutorState& state, size_t reg0, size_t reg1) {
  uint32_t new_value =
    state.integral_registers[reg0] - state.integral_registers[reg1];
  state.ZF = new_value == static_cast<uint32_t>(0);
  state.SF =
    (new_value >> static_cast<uint32_t>(31) == static_cast<uint32_t>(1));
  state.CF = state.integral_registers[reg0] < state.integral_registers[reg1];
  state.OF = (state.integral_registers[reg0] >> static_cast<uint32_t>(31) !=
              state.integral_registers[reg1] >> static_cast<uint32_t>(31)) &&
             (new_value >> static_cast<uint32_t>(31) !=
              state.integral_registers[reg0] >> static_cast<uint32_t>(31));
}

void cmpf(struct ExecutorState& state, size_t reg0, size_t reg1) {
  float new_value =
    state.float_registers[reg0] - state.float_registers[reg1];
  state.ZF = new_value == 0.f;
  state.SF =
    (*reinterpret_cast<uint32_t*>(&new_value) >> static_cast<uint32_t>(31) == static_cast<uint32_t>(1));
  state.CF = std::abs(state.float_registers[reg0]) < std::abs(state.float_registers[reg1]);
  state.OF =
    state.float_registers[reg0] * state.float_registers[reg1] < 0.f &&
    new_value * state.float_registers[reg0] < 0;

}

void jmp(struct ExecutorState& state, size_t label) {
  state.program_counter = label;
  --state.program_counter;
}

void jz(struct ExecutorState& state, size_t label) {
  if (state.ZF == 1) {
    jmp(state, label);
  }
}

void jnz(struct ExecutorState& state, size_t label) {
  if (state.ZF == 0) {
    jmp(state, label);
  }
}

void jg(struct ExecutorState& state, size_t label) {
  if (!state.ZF && (state.SF == state.OF)) {
    jmp(state, label);
  }
}

void jge(struct ExecutorState& state, size_t label) {
  if (state.SF == state.OF) {
    jmp(state, label);
  }
}

void jl(struct ExecutorState& state, size_t label) {
  if (state.SF != state.OF) {
    jmp(state, label);
  }
}

void jle(struct ExecutorState& state, size_t label) {
  if (state.ZF || (state.SF != state.OF)) {
    jmp(state, label);
  }
}

void subrr(struct ExecutorState& state, size_t reg0, size_t reg1) {
  state.integral_registers[reg0] -= state.integral_registers[reg1];
}

void subfrr(struct ExecutorState& state, size_t reg0, size_t reg1) {
  state.float_registers[reg0] -= state.float_registers[reg1];
}

void sqrtf(struct ExecutorState& state, size_t reg0) {
  state.float_registers[reg0] = std::sqrt(state.float_registers[reg0]);
}

void divfrr(struct ExecutorState& state, size_t reg0, size_t reg1) {
  state.float_registers[reg0] /= state.float_registers[reg1];
}

