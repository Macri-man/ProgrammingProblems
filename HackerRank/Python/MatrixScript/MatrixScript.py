#!/bin/python3

import math
import os
import random
import re
import sys

first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)
    

col_strs = [''.join(matrix[row][col] for row in range(n)) for col in range(m)]
full_str = ''.join(col_strs)

pattern = r'(?<=\w)[^\w]+(?=\w)'
decoded = re.sub(pattern, ' ', full_str)

print(decoded)
