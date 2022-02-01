# https://www.acmicpc.net/problem/3009
x1, y1 = list(map(int, input().split(' ')))
x2, y2 = list(map(int, input().split(' ')))
x3, y3 = list(map(int, input().split(' ')))

xs = [x1, x2, x3]
ys = [y1, y2, y3]

for i in xs:
    if xs.count(i) == 1:
        print(i, end=' ')
        break

for i in ys:
    if ys.count(i) == 1:
        print(i, end=' ')
        break

