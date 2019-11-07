#include <PikaExecutor.h>
#include <InstructionsDefines.h>
void pushc(struct ExecutorState& state, uint32_t constant) { PUSH(VAL(TOINT(constant))); }
void pushr(struct ExecutorState& state, size_t reg0) { PUSH(VAL(TOINT(IREG(reg0)))); }
void pushfc(struct ExecutorState& state, uint32_t constant) { PUSH(VAL(TOFLOAT(constant))); }
void pushfr(struct ExecutorState& state, size_t reg0) { PUSH(VAL(FREG(reg0))); }
void movrr(struct ExecutorState& state, size_t reg0, size_t reg1) { IREG(reg0) = IREG(reg1); }
void movrc(struct ExecutorState& state, size_t reg0, uint32_t constant) { IREG(reg0) = constant; }
void movfrr(struct ExecutorState& state, size_t reg0, size_t reg1) { FREG(reg0) = FREG(reg1); }
void movfrc(struct ExecutorState& state, size_t reg0, uint32_t constant) { FREG(reg0) = TOFLOAT(constant); }
void popr(struct ExecutorState& state, size_t reg0) { IREG(reg0) = ITOP; POP; }
void popfr(struct ExecutorState& state, size_t reg0) { FREG(reg0) = FTOP; POP; }
void addrr(struct ExecutorState& state, size_t reg0, size_t reg1) { IREG(reg0) += IREG(reg1); }
void addfrr(struct ExecutorState& state, size_t reg0, size_t reg1) { FREG(reg0) += FREG(reg1); }
void mulrr(struct ExecutorState& state, size_t reg0, size_t reg1) { IREG(reg0) *= IREG(reg1); }
void mulfrr(struct ExecutorState& state, size_t reg0, size_t reg1) { FREG(reg0) *= FREG(reg1); }
void mulfrc(struct ExecutorState& state, size_t reg0, uint32_t constant) { FREG(reg0) *= TOFLOAT(constant); }
void inint(struct ExecutorState& state) { uint32_t in; scanf("%d", &in); PUSH(VAL(TOINT(in))); }
void inch(struct ExecutorState& state) { int32_t ch; ch = getchar(); PUSH(VAL(TOINT(ch))); }
void inf(struct ExecutorState& state) { float fl; scanf("%f", &fl); PUSH(VAL(fl)); }
void outint(struct ExecutorState& state) { printf("%d", ITOP); }
void outch(struct ExecutorState& state) { printf("%c", ITOP); }
void outf(struct ExecutorState& state) { printf("%f", FTOP); }
void cmp(struct ExecutorState& state, size_t reg0, size_t reg1) { auto nv = IREG(reg0) - IREG(reg1); ZF = nv == 0; SF = (nv >> 31) == 1; CF = IREG(reg0) < IREG(reg1); OF = ((IREG(reg0) >> 31) != (IREG(reg1) >> 31)) && ((nv >> 31) != (IREG(reg0) >> 31)); }
void cmpf(struct ExecutorState& state, size_t reg0, size_t reg1) { float nv = FREG(reg0) - FREG(reg1); ZF = nv == 0; SF = (TOINT(nv) >> 31) == 1; CF = abs(FREG(reg0)) < abs(FREG(reg1)); OF = FREG(reg0) * FREG(reg1) < 0 && nv * FREG(reg0) < 0; }
void jmp(struct ExecutorState& state, size_t label) { PC = label; PC -= 1; }
void jz(struct ExecutorState& state, size_t label) { if (ZF) jmp(state, label); }
void jnz(struct ExecutorState& state, size_t label) { if (!ZF) jmp(state, label); }
void jg(struct ExecutorState& state, size_t label) { if (!ZF && (SF == OF)) jmp(state, label); }
void jge(struct ExecutorState& state, size_t label) { if (SF == OF) jmp(state, label); }
void jl(struct ExecutorState& state, size_t label) { if (SF != OF) jmp(state, label); }
void jle(struct ExecutorState& state, size_t label) { if (ZF || (SF != OF)) jmp(state, label); }
void subrr(struct ExecutorState& state, size_t reg0, size_t reg1) { IREG(reg0) -= IREG(reg1); }
void subfrr(struct ExecutorState& state, size_t reg0, size_t reg1) { FREG(reg0) -= FREG(reg1); }
void sqrtf(struct ExecutorState& state, size_t reg0) { FREG(reg0) = sqrt(FREG(reg0)); }
void divfrr(struct ExecutorState& state, size_t reg0, size_t reg1) { FREG(reg0) /= FREG(reg1); }
#undef TOFLOAT
#undef TOINT
#undef ITOP
#undef FTOP
#undef PUSH
#undef POP
#undef PC
#undef IREG
#undef FREG
#undef ZF
#undef SF
#undef CF
#undef OF
