#pragma once
#define TOFLOAT(x) *reinterpret_cast<const float*>(&x)
#define TOINT(x) *reinterpret_cast<const uint32_t*>(&x)
#define TOP state.stack.Top()
#define PUSH(x) state.stack.Push(x)
#define POP state.stack.Pop()
#define PC state.program_counter
#define IREG(x) state.integral_registers[x]
#define FREG(x) state.float_registers[x]
#define ZF state.ZF
#define SF state.SF
#define CF state.CF
#define OF state.OF