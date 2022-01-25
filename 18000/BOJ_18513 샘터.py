# https://www.acmicpc.net/problem/18513
n, k = input().split()
n = int(n)
k = int(k)

lake = list(map(int, input().split(' ')))
home = list()
checked = list()

for i in lake:
    home.append(i)
    checked.append(i)

cnt = 0
unhappy = 0
dis = 1


while cnt < k:
    l = len(home)
    #print(home)
    for i in range(l):
        p = home.pop(0)

        if p-1 not in checked:
            print('I append %d'%(p-1))
            home.append(p-1)
            checked.append(p-1)
            unhappy += dis
            cnt += 1
        
        if cnt == k:
            break

        if p+1 not in checked:
            print('I append %d'%(p+1))
            home.append(p+1)
            checked.append(p+1)
            unhappy += dis
            cnt += 1

    dis += 1

print(unhappy)