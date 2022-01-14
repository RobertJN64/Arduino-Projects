"""
First Chip (address 0 - 511)

HLT - Halt
MI  - Memory Address In (Active Low)
RI  - Ram In
RO  - Ram Out (Active Low)
IO  - Instruction Register Out (Active Low)
II  - Instruction Register In (Active Low)
AI  - A Register In (Active Low)
AO  - A Register Out (Active Low)

Second Chip (address 512 - 1023)

EO  - Sum Out (Active Low)
SU  - Subtract
BI  - B Register In (Active Low)
OI  - Output Register In
CE  - Enable Program Counter
CO  - Program Counter Out (Active Low)
J   - Jump (Active Low)
FI  - Flags Register In (Active Low)
"""

order = ['HLT', 'MI', 'RI', 'RO', 'IO', 'II', 'AI', 'AO',
         'EO',  'SU', 'BI', 'OI', 'CE', 'CO', 'J',  'FI']

#Control Codes (Z) = Zero Flag, (C) = Carry FLag, '!' = Not

instruction_groups = {
    # Control Flow
    'NOP': ['MI CO', 'RO II CE'], #No Operation
    'HLT': ['MI CO', 'RO II CE', 'HLT'], #Halt

    'JMP': ['MI CO', 'RO II CE', 'IO J'], #Jump
    'JEZ': ['MI CO', 'RO II CE', 'Z IO J'], #Jump if 0
    'JNZ': ['MI CO', 'RO II CE', '!Z IO J'], #Jump if not 0
    'JIC': ['MI CO', 'RO II CE', 'C IO J'], #Jump if carry
    'JNC': ['MI CO', 'RO II CE', '!C IO J'], #Jump if not carry

    #Output
    'MOT': ['MI CO', 'RO II CE', 'IO MI', 'RO OI'], #Moves memory address into output register
    'AOT': ['MI CO', 'RO II CE', 'AO OI'], #Moves A register into output register

    # Memory
    'MLA': ['MI CO', 'RO II CE', 'IO MI', 'RO AI'], #Load A Register from Memory
    'VLA': ['MI CO', 'RO II CE', 'IO AI'], #Load A Register with value
    'MLB': ['MI CO', 'RO II CE', 'IO MI', 'RO BI'], #Load B Register from Memory
    'VLB': ['MI CO', 'RO II CE', 'IO BI'], #Load B Register with value
    'STA': ['MI CO', 'RO II CE', 'IO MI', 'AO RI'], #Store value from A Register into memory

    #ALU
    'ADD': ['MI CO', 'RO II CE', 'IO MI', 'EO RI FI'], #Add A + B and store to ram
    'SUB': ['MI CO', 'RO II CE', 'IO MI', 'EO RI SU FI'], #Subtract A - B and store to ram
    'INC': ['MI CO', 'RO II CE', 'IO MI', 'RO BI', 'EO AI FI'], #Increments A register by value
    'DEC': ['MI CO', 'RO II CE', 'IO MI', 'RO BI', 'EO AI FI SU'] #Deincrements B register by value
}

def validate_instructions():
    for inc, cmd in instruction_groups.items():
        for group in cmd:
            for item in group.split():
                if item not in order + ['!Z', 'Z', 'C', '!C']:
                    raise Exception(f"ERROR: {item} not found in {inc}")



def validate_asm():
    cmds = []
    with open('asm_instructions.txt') as f:
        count = 0
        for line in f.readlines():
            line = line.lstrip()
            cmd = line.split('#')[0].strip()
            if cmd != "":
                count += 1
                if count > 16:
                    raise Exception("More than 16 cmds.")
                else:
                    cmds.append(cmd)
                if cmd not in instruction_groups.keys():
                    raise Exception("Invalid CMD: ", cmd)
    return cmds

def hex_digits(num):
    s = hex(num)
    if len(s) == 3:
        s = s[0:2] + '0' + s[2:3]
    return s

def cmd_cost(group, First_EEPROM):
    cost = 0
    for c in group:
        if c in order:
            value = order.index(c)
            if First_EEPROM and value < 8:
                cost += 2 ** value
            if not First_EEPROM and value >= 8:
                cost += 2 ** (value - 8)

    return hex_digits(cost)


def pprint_data(l):
    with open("microcode_data.txt", 'w+') as f:
        f.write("{\n")
        for i in range(0, int(2048/64)):
            for j in range(0, 64):
                f.write(l[i * 64 + j])
                f.write(', ')
            f.write('\n')
        f.write('};\n')

def main():
    validate_instructions()
    cmds = validate_asm()

    m = 0
    for cmd in cmds:
        m = max(len(instruction_groups[cmd]), m)
    print("Max Micro Code Len Required:", m)
    assert m <= 8

    data = ['0x00'] * 2048

    # Both Flags False
    for index, cmd in enumerate(cmds):
        index = index * 8

        for i in range(0, 8):
            if i < len(instruction_groups[cmd]):
                group = instruction_groups[cmd][i].split()
                if 'Z' in group:
                    group = ''
                if 'C' in group:
                    group = ''
                data[index + i] = cmd_cost(group, True)
                data[index + i + 512] = cmd_cost(group, False)

    # Zero Flag True, Carry Flag False
    for index, cmd in enumerate(cmds):
        index = index * 8 + 128

        for i in range(0, 8):
            if i < len(instruction_groups[cmd]):
                group = instruction_groups[cmd][i].split()
                if '!Z' in group:
                    group = ''
                if 'C' in group:
                    group = ''
                data[index + i] = cmd_cost(group, True)
                data[index + i + 512] = cmd_cost(group, False)

    # Carry Flag True, Zero Flag False
    for index, cmd in enumerate(cmds):
        index = index * 8 + 256

        for i in range(0, 8):
            if i < len(instruction_groups[cmd]):
                group = instruction_groups[cmd][i].split()
                if 'Z' in group:
                    group = ''
                if '!C' in group:
                    group = ''
                data[index + i] = cmd_cost(group, True)
                data[index + i + 512] = cmd_cost(group, False)

    # Both Flags True
    for index, cmd in enumerate(cmds):
        index = index * 8 + 384

        for i in range(0, 8):
            if i < len(instruction_groups[cmd]):
                group = instruction_groups[cmd][i].split()
                if '!Z' in group:
                    group = ''
                if '!C' in group:
                    group = ''
                data[index + i] = cmd_cost(group, True)
                data[index + i + 512] = cmd_cost(group, False)

    pprint_data(data)

main()