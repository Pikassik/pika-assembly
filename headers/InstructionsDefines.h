#pragma once
#define TOINT(x) reinterpret_cast<const uint32_t&>(x)
#define TOFLOAT(x) reinterpret_cast<const float&>(x)
#define VAL(x) ExecutorState::StackValue(x)
#define ITOP state.stack.Top().int_v
#define FTOP state.stack.Top().float_v
#define PUSH(x) state.stack.Push(x)
#define POP state.stack.Pop()
#define PC state.program_counter
#define IREG(x) state.integral_registers[x]
#define FREG(x) state.float_registers[x]
#define ZF state.ZF
#define SF state.SF
#define CF state.CF
#define OF state.OF