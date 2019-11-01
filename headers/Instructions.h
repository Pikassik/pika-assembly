#pragma once
#include <cstdint>
#include <string_view>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <PikaExecutor.h>
#include <cmath>

struct Instruction {
  uint32_t instruction;
  uint32_t value;
};

uint32_t RegisterToInt(const char* register_name);
uint32_t Opcode(const Instruction& instr);

namespace instructions::internal {

} // namespace instructions::internal


void pushc(struct ExecutorState& state, uint32_t constant);
void pushr(struct ExecutorState& state, size_t reg0);
void pushfc(struct ExecutorState& state, uint32_t constant);
void pushfr(struct ExecutorState& state, size_t reg0);
void movrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void movrc(struct ExecutorState& state, size_t reg0, uint32_t constant);
void movfrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void movfrc(struct ExecutorState& state, size_t reg0, uint32_t constant);
void popr(struct ExecutorState& state, size_t reg0);
void popfr(struct ExecutorState& state, size_t reg0);
void addrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void addfrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void mulrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void mulfrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void mulfrc(struct ExecutorState& state, size_t reg0, uint32_t constant);
void inint(struct ExecutorState& state);
void inch(struct ExecutorState& state);
void inf(struct ExecutorState& state);
void outint(struct ExecutorState& state);
void outch(struct ExecutorState& state);
void outf(struct ExecutorState& state);
void cmp(struct ExecutorState& state, size_t reg0, size_t reg1);
void cmpf(struct ExecutorState& state, size_t reg0, size_t reg1);
void jmp(struct ExecutorState& state, size_t label);
void jz(struct ExecutorState& state, size_t label);
void jnz(struct ExecutorState& state, size_t label);
void jg(struct ExecutorState& state, size_t label);
void jge(struct ExecutorState& state, size_t label);
void jl(struct ExecutorState& state, size_t label);
void jle(struct ExecutorState& state, size_t label);
void subrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void subfrr(struct ExecutorState& state, size_t reg0, size_t reg1);
void sqrtf(struct ExecutorState& state, size_t reg0);
void divfrr(struct ExecutorState& state, size_t reg0, size_t reg1);
