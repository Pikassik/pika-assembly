INSTRUCTION("movrr", 0x1,  
{
current_instruction.instruction = 0x1;
current_instruction.value = 0;
  
current_instruction.instruction +=
RegisterToInt(strtok(nullptr, " ")) << 28;
  
current_instruction.instruction +=
RegisterToInt(strtok(nullptr, " ")) << 30;
})
INSTRUCTION("pushc", 0x2,  
{
current_instruction.instruction = 0x2;
current_instruction.value = 0;
  
current_instruction.value =
atoi(strtok(nullptr, " "));
})
INSTRUCTION("popr", 0x3,  
{
current_instruction.instruction = 0x3;
current_instruction.value = 0;
  
current_instruction.instruction +=
RegisterToInt(strtok(nullptr, " ")) << 28;
})
INSTRUCTION("add", 0x4,  
{
current_instruction.instruction = 0x4;
current_instruction.value = 0;
})
INSTRUCTION("mul", 0x5,  
{
current_instruction.instruction = 0x5;
current_instruction.value = 0;
})
INSTRUCTION("movrc", 0xF1,  
{
current_instruction.instruction = 0xF1;
current_instruction.value = 0;
  
current_instruction.instruction +=
RegisterToInt(strtok(nullptr, " ")) << 28;
  
current_instruction.value =
atoi(strtok(nullptr, " "));
})
