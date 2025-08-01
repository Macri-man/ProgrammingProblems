# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
from itertools import product

K, M = map(int, sys.stdin.readline().split())

lists = []
for _ in range(K):
    data = list(map(int, sys.stdin.readline().split()))
    Ni = data[0]
    arr = data[1:]
    lists.append(arr)

max_value = 0

for combo in product(*lists):
    s = sum(x*x for x in combo) % M
    if s > max_value:
        max_value = s

print(max_value)