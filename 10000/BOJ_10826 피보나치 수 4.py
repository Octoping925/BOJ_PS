# https://www.acmicpc.net/problem/10826
n = int(input())
fibo = dict()

fibo[0] = 0
fibo[1] = 1

for i in range(2, n+1):
    fibo[i] = fibo[i-1] + fibo[i-2]

print(fibo[n])
