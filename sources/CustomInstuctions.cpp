#include <PikaExecutor.h>
#include <InstructionsDefines.h>

void cmp(struct ExecutorState& state, size_t reg0, size_t reg1) {
  LET nv = IREG(reg0) - IREG(reg1);
  ZF = nv == 0;
  SF = (nv >> 31) == 1;
  CF = IREG(reg0) < IREG(reg1);
  OF = ((IREG(reg0) >> 31) != (IREG(reg1) >> 31))
      && ((nv >> 31) != (IREG(reg0) >> 31));
}

void cmpf(struct ExecutorState& state, size_t reg0, size_t reg1) {
  float nv = FREG(reg0) - FREG(reg1);
  ZF = nv == 0;
  SF = (TOINT(nv) >> 31) == 1;
  CF = abs(FREG(reg0)) < abs(FREG(reg1));
  OF = FREG(reg0) * FREG(reg1) < 0 && nv * FREG(reg0) < 0;
}

#include <InstructionsUndefs.h>