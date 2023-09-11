import time
import sys
from PIL import Image

# input = []
# with open('executables/test.exe', 'rb') as f:
#     input = f.read()

# val_bin = []

# for val in input:
#     tmp = bin(int(val)).split("b")[1]
#     while len(tmp) < 8:
#         tmp = '0' + tmp
#     val_bin.append(tmp)


# print(len(val_bin))

# lesen des bildes
im = Image.open('test.png', 'r')
pixel_values = list(im.getdata())


str_bin = [str(num) for num in pixel_values]
for i in range(len(str_bin)):
    if str_bin[i] == '255':
        str_bin[i] = '1'

str_byte = [''] * int(len(str_bin) / 8)

for i in range(len(str_bin)):
    str_byte[i // 8] += str_bin[i]

# so oder als einen string bekommt der spieler die information wie in val_bin
with open('executables/new.exe', 'wb') as f:
    for _, val in enumerate(str_byte):
        f.write(bytes(int(val, 2).to_bytes((len(val) + 7) // 8, 'big')))
