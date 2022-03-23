# https://www.acmicpc.net/problem/1620
n, m = map(int, input().split(' '))

dogamDict = dict()
dogamArr = list()

for i in range(n):
    txt = input()
    dogamDict[txt] = i
    dogamArr.append(txt)

for i in range(m):
    txt = input()
    if(txt.isdigit()):
        print(dogamArr[int(txt)-1])
    else:
        print(dogamDict[txt]+1)