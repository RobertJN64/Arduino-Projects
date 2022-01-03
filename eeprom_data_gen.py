MAX_ADDRESS = 2048

import random

assert MAX_ADDRESS % 64 == 0, "Address must be divisible by 64"

print('{', end='')
for y in range(0, int(MAX_ADDRESS/64)):
    for x in range(0, 64):
        char = random.randint(0, 9)
        s = "0x" + str(char) + str(char) + ','
        print(s, end=' ')
    print()
print('};')