from time import sleep

def c_neg(convert, val):
    if not convert:
        return val
    if val >= 128:
        return val - 256
    else:
        return val

def simulate(instructions, var_defaults):
    verbose = input("Verbose? ") == 'y'
    allow_neg = input("Output could be negative? ") == 'y'
    memory: list = [0] * 16
    A = 0
    B = 0
    Zero = False
    Carry = False
    P_Counter = 0

    index = 0
    for index, instruction in enumerate(instructions):
        memory[index] = (instruction.cmd, instruction.arg)
    for j, var_value in enumerate(var_defaults):
        j = index + j + 1
        memory[j] = var_value

    while True:
        cmd = memory[P_Counter]
        P_Counter += 1
        if P_Counter == 16:
            P_Counter = 0

        assert isinstance(cmd, tuple), "Program leaked into memory."
        cmd, value = cmd

        if verbose:
            print(f"Running cmd: {cmd}")
        if cmd == 'NOP':
            pass

        elif cmd == 'HLT':
            break

        elif cmd == 'JMP':
            P_Counter = value

        elif cmd == 'JEZ':
            if Zero:
                P_Counter = value

        elif cmd == 'JNZ':
            if not Zero:
                P_Counter = value

        elif cmd == 'JIC':
            if Carry:
                P_Counter = value

        elif cmd == 'JNC':
            if not Carry:
                P_Counter = value

        elif cmd == 'MOT':
            print(f"Output: {c_neg(allow_neg, memory[value])}")

        elif cmd == 'AOT':
            print(f"Output: {c_neg(allow_neg, A)}")

        elif cmd == 'MLA':
            A = memory[value]

        elif cmd == 'VLA':
            A = value

        elif cmd == 'MLB':
            B = memory[value]

        elif cmd == 'VLB':
            B = value

        elif cmd == 'STA':
            memory[value] = A

        elif cmd == 'ADD':
            s = A + B
            if s > 255:
                s = s%256
                Carry = True
            else:
                Carry = False

            Zero = s == 0
            memory[value] = s

        elif cmd == 'SUB':
            s = A + (255 - B + 1)
            if s > 255:
                s = s % 256
                Carry = True
            else:
                Carry = False

            Zero = s == 0
            memory[value] = s

        elif cmd == 'INC':
            A = A + value
            B = value
            if A > 255:
                A = A % 256
                Carry = True
            else:
                Carry = False

            Zero = A == 0

        elif cmd == 'DEC':
            A = A + (255 - value + 1)
            B = value
            if A > 255:
                A = A % 256
                Carry = True
            else:
                Carry = False

            Zero = A == 0

        if verbose:
            print(f"A: {A}  B: {B}  Memory: {memory}  Zero: {Zero} Carry: {Carry} PC: {P_Counter}")
            sleep(0.1)
        sleep(0.01)