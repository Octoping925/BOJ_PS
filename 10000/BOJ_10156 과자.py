# https://www.acmicpc.net/problem/10156
k, n, m = input().split(' ')
print(max(int(k)*int(n)-int(m), 0))
