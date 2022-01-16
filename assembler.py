import tabulate
from simulator import simulate

def binary(num):
    b = bin(num)[2:]
    b = '0' * (4 - len(b)) + b
    return b.replace('1', '↑').replace('0', '_')



class Instruction:
    def __init__(self, cmd, labellist, cmds):
        cmd = cmd.split(' ')
        self.cmd = cmd[0]
        if self.cmd not in cmds:
            raise Exception(f"CMD {self.cmd} not found.")
        if len(cmd) > 1 and cmd[0] in ['NOP', 'HLT', 'AOT']:
            raise Exception(f"CMD {self.cmd} should not have args.")
        elif len(cmd) == 1 and cmd[0] not in ['NOP', 'HLT', 'AOT']:
            raise Exception(f"CMD {self.cmd} needs args.")
        self.arg = cmd[1] if len(cmd) > 1 else 0

        self.labels = labellist

        self.cmdnum = cmds.index(self.cmd)

    def find_label(self, instructions):
        if self.cmd in ['JMP', 'JEZ', 'JNZ', 'JIC', 'JNC']:
            for index, inc in enumerate(instructions):
                if self.arg in inc.labels:
                    self.arg = index

    def find_vars(self, varlist, valuelist, inccount):
        if self.cmd in ['MLA', 'MLB', 'STA', 'ADD', 'SUB', 'MOT']:
            try:
                self.arg = int(self.arg)
            except ValueError:
                if self.arg not in varlist:
                    varlist.append(self.arg)
                    valuelist.append(0)
                self.arg = varlist.index(self.arg) + inccount

        elif self.cmd in ['VLA', 'VLB', 'INC', 'DEC']:
            try:
                self.arg = int(self.arg)
            except ValueError:
                raise Exception(f"CMD {self.cmd} should have numerical arg.")
            assert int(self.arg) < 16, "Numerical arg must be 15 or less"

    def __repr__(self):
        return f'Instruction with cmd: {self.cmd} ({hex(self.cmdnum)}) and arg: {self.arg} with labels: {self.labels}'


def main():
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

    fname = input("File Name: ")
    #fname = 'CPU_Test'
    with open('CodeSamples/' + fname + '.txt') as f:
        lines = [line.split(';')[0].strip() for line in f.readlines() if line.split(';')[0].strip() != ""]

    labels = []
    instructions = []
    var_list = []
    var_value_list = []
    for line in lines:
        if '%' in line:
            varname, value = line.replace('%', '').split()
            value = int(value)


            if value < 0:
                value = value%256

            var_list.append(varname)
            var_value_list.append(value)
            assert value < 256, "Variables must not be higher than 255"
        elif ':' not in line:
            instructions.append(Instruction(line, labels, cmds))
            labels = []
        else:
            labels.append(line.replace(':', ''))

    for i in instructions:
        i.find_label(instructions)

    for i in instructions:
        i.find_vars(var_list, var_value_list, len(instructions))

    assert len(var_list) + len(instructions) <= 16, "Too many variables or instructions."

    print("Assembled Program:")
    tabledata = []
    index = 0
    for index, inc in enumerate(instructions):
        tabledata.append([hex(index), inc.cmd + ' (' + hex(inc.cmdnum) + ')', inc.arg,
                          binary(index) + ' | ' + binary(inc.cmdnum) + ' ' + binary(inc.arg)])
    print(tabulate.tabulate(tabledata, headers=['Adress', 'Command', 'Args', 'Memory']))

    print("\nVariables:")
    tabledata = []
    for j, (var, value) in enumerate(zip(var_list, var_value_list)):
        j = index + j + 1
        tabledata.append([hex(j), var, value, binary(j) + ' | ' + binary(int(value/16)) +
                          ' ' + binary(value%16)])
    print(tabulate.tabulate(tabledata, headers=['Adress', 'Command', 'Args', 'Memory']))

    print()
    if input("Run simulation: ") == 'y':
        simulate(instructions, var_value_list)

if __name__ == '__main__':
    main()

