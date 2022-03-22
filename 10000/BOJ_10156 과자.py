# https://www.acmicpc.net/problem/10156
k, n, m = map(int, input().split())
print(max(k*n-m, 0))
