import cv2
import numpy as np
import sys

# calculate the best picture ratio
# calc the sqrt of length
# round the the value and go up/down by one until the first whole integer when length / i
bin_str = 0

with open('pixels.txt', 'r') as f:
    bin_str = f.read()

n = len(bin_str)
n_2 : float = np.sqrt(n)

x_size = 0
i = 0
while True:
    if n_2.is_integer():
        x_size = n_2
        break

    up = round(n_2 + i, 0)
    down = round(n_2 - i, 0)

    if (n / up).is_integer(): 
        x_size = up
        break

    if (n / down).is_integer():
        x_size = down
        break

    i += 1

print(f"x: {x_size}    y: {n / x_size}")

bits = np.zeros((int(x_size), int(n / x_size)), dtype=np.uint8)

cnt = 0
for i in range(bits.shape[0]):
    for j in range(bits.shape[1]):
        bits[i, j] = 255 if bin_str[cnt] == '1' else 0
        cnt += 1

cv2.imwrite('test.png', bits)