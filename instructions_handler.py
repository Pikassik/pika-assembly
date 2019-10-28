import sys


instructions = open(sys.argv[1] + '/instructions', 'r')
instructions_header = open(sys.argv[1] + '/headers/CompileInstructions.h', 'w')

default_instruction =\
"""  
{{
current_instruction.instruction = {opcode};
current_instruction.value = 0;
"""

reg1 =\
"""  
current_instruction.instruction +=
RegisterToInt(strtok(nullptr, \" \")) << 28;
"""

reg2 =\
"""  
current_instruction.instruction +=
RegisterToInt(strtok(nullptr, \" \")) << 30;
"""

const =\
"""  
current_instruction.value =
atoi(strtok(nullptr, \" \"));
"""

constF =\
"""  
current_instruction.value =
*reinterpret_cast<uint32_t*>(
&static_cast<float>(atof(strtok(nullptr, \" \"))));  
"""
label =\
"""
current_instruction.value = labels[strtok(nullptr, \" \")];
"""

for line in instructions:
    splitted = line.split()
    current_instruction = default_instruction

    if len(splitted) >= 3:
        if splitted[2] == 'reg':
            current_instruction += reg1
        elif splitted[2] == 'const':
            current_instruction += const
        elif splitted[2] == 'constF':
            current_instruction += constF
        elif splitted[2] == 'label':
            current_instruction += label

    if len(splitted) >= 4:
        if splitted[3] == 'reg':
            current_instruction += reg2
        elif splitted[3] == 'const':
            current_instruction += const
        elif splitted[3] == 'constF':
            current_instruction += constF
    current_instruction += '}}'

    instructions_header.write(
        ("INSTRUCTION(\"{instr_name}\", {opcode}," +
         current_instruction + ")\n").
        format(instr_name=splitted[0], opcode=splitted[1]))

instructions.close()
instructions_header.close()
