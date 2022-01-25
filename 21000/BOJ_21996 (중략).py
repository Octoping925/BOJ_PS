# https://www.acmicpc.net/problem/21966
n = int(input())
txt = input()

if n <= 25:
    print(txt)

elif n > 25:
    jr = txt[11 : -11]
    if jr in txt[:11]+txt[-11:]:
        print(txt[:11] + "..." + txt[-11:])
    else:
        print(txt[:9] + "......" + txt[-10:])