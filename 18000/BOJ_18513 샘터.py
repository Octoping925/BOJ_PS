# https://www.acmicpc.net/problem/18513
n, k = map(int, input().split())
home = list(map(int, input().split()))
checked = dict()

for i in home:
    checked[i] = 1

cnt = 0
unhappy = 0
dis = 0

while cnt < k:
    l = len(home)
    dis += 1
    for i in range(l):
        p = home.pop(0)

        if p-1 not in checked:
            home.append(p-1)
            checked[p-1] = 1
            unhappy += dis
            cnt += 1
        
        if cnt == k:
            break

        if p+1 not in checked:
            home.append(p+1)
            checked[p+1] = 1
            unhappy += dis
            cnt += 1
        
        if cnt == k:
            break

print(unhappy)