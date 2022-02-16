# https://www.acmicpc.net/problem/11728
input()
n = list(map(int, input().split(' ')))
m = list(map(int, input().split(' ')))
n = n + m
n.sort()
for i in n:
    print(i)