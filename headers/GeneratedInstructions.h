#include <PikaExecutor.h>
#include <InstructionsDefines.h>
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

#undef TOFLOAT
#undef TOINT
#undef TOP
#undef PUSH
#undef POP
#undef PC
#undef IREG
#undef FREG
#undef ZF
#undef SF
#undef CF
#undef OF