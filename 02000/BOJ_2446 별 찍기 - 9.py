# https://www.acmicpc.net/problem/2446
n=int(input())
for i in range(1-n, n):
    print(' '*(n-1-abs(i))+'*'*(2*abs(i)+1))