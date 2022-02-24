# https://www.acmicpc.net/problem/4892
cnt = 1
while True:
    k = int(input())
    if k == 0:
        break

    print(f"{cnt}. {'even' if k % 2 == 0 else 'odd'} {k//2}")
    cnt += 1
    