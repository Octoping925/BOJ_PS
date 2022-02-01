# https://www.acmicpc.net/problem/1085
x, y, w, h = list(map(int, input().split(' ')))

print(min(min(x, w-x), min(y, h-y)))