# https://www.acmicpc.net/problem/1064
import math

txt = input().split(' ')
a1, a2 = int(txt[0]), int(txt[1])
b1, b2 = int(txt[2]), int(txt[3])
c1, c2 = int(txt[4]), int(txt[5])

if (c2 - a2) * (b1 - a1) == (b2 - a2) * (c1 - a1):
   print("-1.0")

else:
    ab = (b1 - a1) ** 2 + (b2 - a2) ** 2
    bc = (c1 - b1) ** 2 + (c2 - b2) ** 2
    ca = (c1 - a1) ** 2 + (c2 - a2) ** 2

    max = min = 0

    if ab > bc:
        if ab > ca:
            max = ab
            min = ca if bc > ca else bc
        else:
            max = ca
            min = bc
    else:
        if bc > ca:
            max = bc
            min = ca if ab > ca else ab
        else:
            max = ca
            min = ab
    
    print(2 * (math.sqrt(max) - math.sqrt(min)))