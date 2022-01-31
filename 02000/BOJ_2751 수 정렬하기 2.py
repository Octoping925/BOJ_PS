# https://www.acmicpc.net/problem/2751
import sys
n=int(sys.stdin.readline())
arr=[]
for i in range(n):
    arr.append(int(sys.stdin.readline()))

arr.sort()
for i in arr:
    print(i)