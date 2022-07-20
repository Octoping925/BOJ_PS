# https://www.acmicpc.net/problem/10610
n = list(map(int, list(input())))

if 0 not in n or sum(n) % 3 != 0:
    print(-1)
else:
    n.sort()
    n.reverse()
    print(''.join(map(str, n)))