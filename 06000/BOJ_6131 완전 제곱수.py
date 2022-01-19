# https://www.acmicpc.net/problem/6131
n = int(input())
cnt = 0

for i in range(1, 500):
    for j in range(1, i):
        if i * i == j * j + n:
            cnt += 1

print(cnt)