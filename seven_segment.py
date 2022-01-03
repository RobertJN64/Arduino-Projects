"""
Seven Segment Display

 AAA
F   B
 GGG
E   C
 DDD   H

"""

MAX_ADDRESS = 2048
assert MAX_ADDRESS % 64 == 0, "Address must be divisible by 64"

number_maps = [
    'ABCDEF',  #0
    'BC',      #1
    'ABDEG',   #2
    'ABCDG',   #3
    'BCFG',    #4
    'ACDFG',   #5
    'ACDEFG',  #6
    'ABC',     #7
    'ABCDEFG', #8
    'ABCDFG',  #9
]

letter_costs = {
    'A': 2 ** 4,
    'B': 2 ** 3,
    'C': 2 ** 2,
    'D': 2 ** 1,
    'E': 2 ** 0,
    'F': 2 ** 5,
    'G': 2 ** 6,
    'H': 2 ** 7 #decimal point
}

def hex_digits(num):
    s = hex(num)
    if len(s) == 3:
        s = s[0:2] + '0' + s[2:3]
    return s


def pprint_data(l):
    with open("eeprom_data.txt", 'w+') as f:
        f.write("{")
        for i in range(0, int(MAX_ADDRESS/64)):
            for j in range(0, 64):
                f.write(l[i * 64 + j])
                f.write(', ')
            f.write('\n')
        f.write('};\n')

def num_cost(num):
    if num == ' ':
        return '0x00'
    if num == '-':
        return '0x40'

    val = 0
    for letter in number_maps[int(num)]:
        val += letter_costs[letter]
    return hex_digits(val)

def digit_cost(num, digit):
    num = str(num)
    num = ' ' * (4 - len(str(num))) + num
    return num_cost(num[digit])

def single_digit():
    l = ['0xff'] * MAX_ADDRESS
    for i in range(0, 10):
        l[i] = num_cost(i)
    pprint_data(l)

def all_nums():
    l = ['0xff'] * MAX_ADDRESS
    for i in range(0, 256):
        l[i + 256 * 0] = digit_cost(i, 0)
        l[i + 256 * 1] = digit_cost(i, 1)
        l[i + 256 * 2] = digit_cost(i, 2)
        l[i + 256 * 3] = digit_cost(i, 3)

    for i in range(0, 256):
        if i >= 128:
            digit = i - 256
        else:
            digit = i

        l[i + 256 * 4] = digit_cost(digit, 0)
        l[i + 256 * 5] = digit_cost(digit, 1)
        l[i + 256 * 6] = digit_cost(digit, 2)
        l[i + 256 * 7] = digit_cost(digit, 3)

    pprint_data(l)

#single_digit()
all_nums()