# https://www.acmicpc.net/problem/1013
import re

t = int(input())

for i in range(t):
    txt = input()
    reg = re.compile("((100+1+)|(01))+").search(txt)
    print(reg)
    print("YES" if reg != None and reg.end() == len(txt) else "NO")

# mine: 01 10001 01 1001 1001
# pyth: 01 10001 01 10011 001 (Wrong!)
