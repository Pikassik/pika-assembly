pushc       0x10 const          { PUSH(VAL(TOINT(constant))); }
pushr       0x11 reg            { PUSH(VAL(TOINT(IREG(reg0)))); }
pushfc      0x12 constf         { PUSH(VAL(TOFLOAT(constant))); }
pushfr      0x13 reg            { PUSH(VAL(FREG(reg0))); }
movrr       0x20 reg reg        { IREG(reg0) = IREG(reg1); }
movrc       0x21 reg const      { IREG(reg0) = constant; }
movfrr      0x22 reg reg        { FREG(reg0) = FREG(reg1); }
movfrc      0x23 reg constf     { FREG(reg0) = TOFLOAT(constant); }
popr        0x30 reg            { IREG(reg0) = ITOP; POP; }
popfr       0x31 reg            { FREG(reg0) = FTOP; POP; }
addrr       0x40 reg reg        { IREG(reg0) += IREG(reg1); }
addfrr      0x41 reg reg        { FREG(reg0) += FREG(reg1); }
mulrr       0x50 reg reg        { IREG(reg0) *= IREG(reg1); }
mulfrr      0x52 reg reg        { FREG(reg0) *= FREG(reg1); }
mulfrc      0x53 reg constf     { FREG(reg0) *= TOFLOAT(constant); }
inint       0x60                { uint32_t in; scanf("%d", &in); PUSH(VAL(TOINT(in))); }
inch        0x61                { int32_t ch; ch = getchar(); PUSH(VAL(TOINT(ch))); }
inf         0x62                { float fl; scanf("%f", &fl); PUSH(VAL(fl)); }
outint      0x70                { printf("%d", ITOP); }
outch       0x71                { printf("%c", ITOP); }
outf        0x72                { printf("%f", FTOP); }
cmp         0x80 reg reg        {*}
cmpf        0x81 reg reg        {*}
jmp         0x90 label          { PC = label; PC -= 1; }
jz          0x91 label          { if (ZF) jmp(state, label); }
jnz         0x92 label          { if (!ZF) jmp(state, label); }
jg          0x93 label          { if (!ZF && (SF == OF)) jmp(state, label); }
jge         0x94 label          { if (SF == OF) jmp(state, label); }
jl          0x95 label          { if (SF != OF) jmp(state, label); }
jle         0x96 label          { if (ZF || (SF != OF)) jmp(state, label); }
subrr       0xA0 reg reg        { IREG(reg0) -= IREG(reg1); }
subfrr      0xA1 reg reg        { FREG(reg0) -= FREG(reg1); }
sqrtf       0xB0 reg            { FREG(reg0) = sqrt(FREG(reg0)); }
divfrr      0xC1 reg reg        { FREG(reg0) /= FREG(reg1); }