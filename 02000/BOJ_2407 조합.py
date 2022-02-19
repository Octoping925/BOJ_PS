# https://www.acmicpc.net/problem/2407
import sys
import math
n, m = list(map(int, sys.stdin.readline().split(' ')))
print(math.factorial(n) // (math.factorial(m) * math.factorial(n-m)))