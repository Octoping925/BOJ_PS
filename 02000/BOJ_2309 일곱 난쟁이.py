# https://www.acmicpc.net/problem/2309

arr = []
sum = 0
sw = 0

for i in range(9):
    arr.append(int(input()))
    sum += arr[i]
    
for i in range(9):
    for j in range(i + 1, 9):
        if sum - arr[i] - arr[j] == 100:
            arr.pop(j)
            arr.pop(i)
            sw = 1
            break
    if sw == 1:
        break

arr.sort()
for i in arr:
    print(i)
    