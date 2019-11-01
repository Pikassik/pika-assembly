import sys


instructions = open(sys.argv[1] + '/instructions', 'r')
compile_instructions_header =\
    open(sys.argv[1] + '/headers/CompileInstructions.h', 'w')

"""
Generating compile code
"""

default_instruction =\
"""\
if (!strcmp("{instr_name}", current_instruction_name)) {{
  current_instruction.instruction = {opcode};
  current_instruction.value = 0;
"""

reg1 =\
"""\
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, \" \")) << 28;
"""

reg2 =\
"""\
  current_instruction.instruction +=
  RegisterToInt(strtok(nullptr, \" \")) << 30;
"""

const =\
"""\
  current_instruction.value =
  atoi(strtok(nullptr, \" \"));
"""

constF =\
"""\
  float constf = atof(strtok(nullptr, \" \"));
  current_instruction.value = *reinterpret_cast<uint32_t*>(&constf);  
"""
label =\
"""\
  current_instruction.value = labels_[strtok(nullptr, \" \")];
"""

for line in instructions:
    splitted = line.split()
    current_instruction = default_instruction

    if len(splitted) >= 3:
        if splitted[2] == 'reg' or splitted[2] == 'regf':
            current_instruction += reg1
        elif splitted[2] == 'const':
            current_instruction += const
        elif splitted[2] == 'constf':
            current_instruction += constF
        elif splitted[2] == 'label':
            current_instruction += label

    if len(splitted) >= 4:
        if splitted[3] == 'reg' or splitted[3] == 'regf':
            current_instruction += reg2
        elif splitted[3] == 'const':
            current_instruction += const
        elif splitted[3] == 'constf':
            current_instruction += constF
    current_instruction +=\
        '  instructions_.push_back(current_instruction);\n  continue;\n}}\n'

    compile_instructions_header.write(
        (current_instruction).
        format(instr_name=splitted[0], opcode=splitted[1]))

compile_instructions_header.close()

execute_instructions_header = open(sys.argv[1] + '/headers/ExecuteInstructions.h', 'w')


"""
Generating execution code
"""

default_instruction =\
"""\
{
"""

const_or_label =\
"""\
  uint32_t arg{number} = instr.value;
"""

reg1 =\
"""\
  size_t arg{number} = (instr.instruction << static_cast<uint32_t>(2)) >> static_cast<uint32_t>(30);    
"""

reg2 =\
"""\
  size_t arg{number} = instr.instruction >> static_cast<uint32_t>(30);
"""

constF =\
"""\
  float arg{number} = instr.value;
"""

instructions.seek(0)

for line in instructions:
    splitted = line.split()
    current_instruction = default_instruction
    if len(splitted) >= 3:
        if splitted[2] == 'reg':
            current_instruction += reg1.format(number=0)
        elif splitted[2] == 'const':
            current_instruction += const_or_label.format(number=0)
        elif splitted[2] == 'constf':
            current_instruction += constF.format(number=0)
        elif splitted[2] == 'label':
            current_instruction += const_or_label.format(number=0)

    if len(splitted) >= 4:
        if splitted[3] == 'reg':
            current_instruction += reg2.format(number=1)
        elif splitted[3] == 'const':
            current_instruction += const_or_label.format(number=1)
        elif splitted[3] == 'constf':
            current_instruction += constF.format(number=1)
    current_instruction += '  ' + splitted[0]
    if len(splitted) - 2 == 0:
        current_instruction += "(state_);\n"
    elif len(splitted) - 2 == 1:
        current_instruction += "(state_, arg0);\n"
    elif len(splitted) - 2 == 2:
        current_instruction += "(state_, arg0, arg1);\n"
    current_instruction += "  break;\n}"
    args_count = len(splitted) - 2
    execute_instructions_header.write(
        "case {opcode}: {code}\n".
        format(opcode=splitted[1], code=current_instruction))

execute_instructions_header.close()
instructions.close()
