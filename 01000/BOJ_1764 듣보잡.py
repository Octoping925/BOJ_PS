# https://www.acmicpc.net/problem/1764
import sys
n, m = list(map(int, sys.stdin.readline().split(' ')))

dut = dict()
dutbo = list()

for i in range(n):
    dut[sys.stdin.readline().strip()] = 1
    
for j in range(m):
    txt = sys.stdin.readline().strip()
    if txt in dut:
        dutbo.append(txt)

print(len(dutbo))
dutbo.sort()
for i in dutbo:
    print(i)