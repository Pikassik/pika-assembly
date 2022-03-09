if (!strcmp("pushc", current_instruction_name)) {
  current_instruction.instruction = 0x10;
  current_instruction.value = 0;
  current_instruction.value =
  atoi(strtok(nullptr, " "));
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("pushr", current_instruction_name)) {
  current_instruction.instruction = 0x11;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("pushfc", current_instruction_name)) {
  current_instruction.instruction = 0x12;
  current_instruction.value = 0;
  float constf = atof(strtok(nullptr, " "));
  current_instruction.value = *reinterpret_cast<uint32_t*>(&constf);  
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("pushfr", current_instruction_name)) {
  current_instruction.instruction = 0x13;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("movrr", current_instruction_name)) {
  current_instruction.instruction = 0x20;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("movrc", current_instruction_name)) {
  current_instruction.instruction = 0x21;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.value =
  atoi(strtok(nullptr, " "));
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("movfrr", current_instruction_name)) {
  current_instruction.instruction = 0x22;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("movfrc", current_instruction_name)) {
  current_instruction.instruction = 0x23;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  float constf = atof(strtok(nullptr, " "));
  current_instruction.value = *reinterpret_cast<uint32_t*>(&constf);  
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("popr", current_instruction_name)) {
  current_instruction.instruction = 0x30;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("popfr", current_instruction_name)) {
  current_instruction.instruction = 0x31;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("addrr", current_instruction_name)) {
  current_instruction.instruction = 0x40;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("addfrr", current_instruction_name)) {
  current_instruction.instruction = 0x41;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("mulrr", current_instruction_name)) {
  current_instruction.instruction = 0x50;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("mulfrr", current_instruction_name)) {
  current_instruction.instruction = 0x52;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("mulfrc", current_instruction_name)) {
  current_instruction.instruction = 0x53;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  float constf = atof(strtok(nullptr, " "));
  current_instruction.value = *reinterpret_cast<uint32_t*>(&constf);  
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("inint", current_instruction_name)) {
  current_instruction.instruction = 0x60;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("inch", current_instruction_name)) {
  current_instruction.instruction = 0x61;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("inf", current_instruction_name)) {
  current_instruction.instruction = 0x62;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("outint", current_instruction_name)) {
  current_instruction.instruction = 0x70;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("outch", current_instruction_name)) {
  current_instruction.instruction = 0x71;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("outf", current_instruction_name)) {
  current_instruction.instruction = 0x72;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("cmp", current_instruction_name)) {
  current_instruction.instruction = 0x80;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("cmpf", current_instruction_name)) {
  current_instruction.instruction = 0x81;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jmp", current_instruction_name)) {
  current_instruction.instruction = 0x90;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jz", current_instruction_name)) {
  current_instruction.instruction = 0x91;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jnz", current_instruction_name)) {
  current_instruction.instruction = 0x92;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jg", current_instruction_name)) {
  current_instruction.instruction = 0x93;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jge", current_instruction_name)) {
  current_instruction.instruction = 0x94;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jl", current_instruction_name)) {
  current_instruction.instruction = 0x95;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("jle", current_instruction_name)) {
  current_instruction.instruction = 0x96;
  current_instruction.value = 0;
  current_instruction.value = labels_[strtok(nullptr, " ")];
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("subrr", current_instruction_name)) {
  current_instruction.instruction = 0xA0;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("subfrr", current_instruction_name)) {
  current_instruction.instruction = 0xA1;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("sqrtf", current_instruction_name)) {
  current_instruction.instruction = 0xB0;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("divfrr", current_instruction_name)) {
  current_instruction.instruction = 0xC1;
  current_instruction.value = 0;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 28;
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, " ")) << 30;
  instructions_.push_back(current_instruction);
  continue;
}
if (!strcmp("end", current_instruction_name)) {
  current_instruction.instruction = 0xFF;
  current_instruction.value = 0;
  instructions_.push_back(current_instruction);
  continue;
}
