import sys


instructions = open(sys.argv[1] + '/instructions', 'r')
instructions_header = open(sys.argv[1] + '/headers/Instructions.h', 'w')


for line in instructions:
    splitted = line.split()
    instructions_header.write(
        "INSTRUCTION({0}, {1})\n".format(splitted[0], splitted[1]))

instructions.close()
instructions_header.close()
