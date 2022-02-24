# https://www.acmicpc.net/problem/14215
arr = list(map(int, input().split()))
arr.sort()

if arr[0] + arr[1] > arr[2]:
    print(sum(arr))
else:
    print((arr[0]+arr[1])*2-1)
