# https://www.acmicpc.net/problem/1092
n = int(input())
crane = list(map(int, input().split(' ')))

m = int(input())
box = list(map(int, input().split(' ')))

crane.sort(reverse=True)
box.sort(reverse=True)

answer = 0
sw = 0
while box:
    for i in range(n):
        for j in range(m):
            if crane[i] < box[j]:
                if i == 0:
                    print(-1)
                    exit(0)

            else:
                box.pop(j)
                m -= 1
                if not box:
                    sw = 1
                break
        if sw == 1:
            break
    
    answer += 1

print(answer)