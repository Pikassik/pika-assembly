case 0x10: {
  uint32_t arg0 = instr.value;
  pushc(state_, arg0);
  break;
}
case 0x11: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  pushr(state_, arg0);
  break;
}
case 0x12: {
  float arg0 = instr.value;
  pushfc(state_, arg0);
  break;
}
case 0x13: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  pushfr(state_, arg0);
  break;
}
case 0x20: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  movrr(state_, arg0, arg1);
  break;
}
case 0x21: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  uint32_t arg1 = instr.value;
  movrc(state_, arg0, arg1);
  break;
}
case 0x22: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  movfrr(state_, arg0, arg1);
  break;
}
case 0x23: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  float arg1 = instr.value;
  movfrc(state_, arg0, arg1);
  break;
}
case 0x30: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  popr(state_, arg0);
  break;
}
case 0x31: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  popfr(state_, arg0);
  break;
}
case 0x40: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  addrr(state_, arg0, arg1);
  break;
}
case 0x41: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  addfrr(state_, arg0, arg1);
  break;
}
case 0x50: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  mulrr(state_, arg0, arg1);
  break;
}
case 0x52: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  mulfrr(state_, arg0, arg1);
  break;
}
case 0x53: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  float arg1 = instr.value;
  mulfrc(state_, arg0, arg1);
  break;
}
case 0x60: {
  inint(state_);
  break;
}
case 0x61: {
  inch(state_);
  break;
}
case 0x62: {
  inf(state_);
  break;
}
case 0x70: {
  outint(state_);
  break;
}
case 0x71: {
  outch(state_);
  break;
}
case 0x72: {
  outf(state_);
  break;
}
case 0x80: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  cmp(state_, arg0, arg1);
  break;
}
case 0x81: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  cmpf(state_, arg0, arg1);
  break;
}
case 0x90: {
  uint32_t arg0 = instr.value;
  jmp(state_, arg0);
  break;
}
case 0x91: {
  uint32_t arg0 = instr.value;
  jz(state_, arg0);
  break;
}
case 0x92: {
  uint32_t arg0 = instr.value;
  jnz(state_, arg0);
  break;
}
case 0x93: {
  uint32_t arg0 = instr.value;
  jg(state_, arg0);
  break;
}
case 0x94: {
  uint32_t arg0 = instr.value;
  jge(state_, arg0);
  break;
}
case 0x95: {
  uint32_t arg0 = instr.value;
  jl(state_, arg0);
  break;
}
case 0x96: {
  uint32_t arg0 = instr.value;
  jle(state_, arg0);
  break;
}
case 0xA0: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  subrr(state_, arg0, arg1);
  break;
}
case 0xA1: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  subfrr(state_, arg0, arg1);
  break;
}
case 0xB0: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  sqrtf(state_, arg0);
  break;
}
case 0xC1: {
  size_t arg0 = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
  size_t arg1 = instr.instruction >> static_cast<uint32_t>(30);
  divfrr(state_, arg0, arg1);
  break;
}
case 0xFF: {
  end(state_);
  break;
}
