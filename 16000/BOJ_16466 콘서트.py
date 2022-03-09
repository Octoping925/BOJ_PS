# https://www.acmicpc.net/problem/16466
global arr

def func():
    for i in range(1, 2200000000):
        if i-1 == len(arr) or i < arr[i-1]:
            return i

n = int(input())
arr = list(map(int, input().split(' ')))
arr.sort()

print(func())