# https://www.acmicpc.net/problem/1036
import sys
global jinsu

jinsu = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def thirtysixtodecimal(txt):
    dec = 0
    for i in range(len(txt)):
        dec += (36 ** i) * jinsu.index(txt[-i-1])
    return dec

def decimaltothirtysix(num):
    txt = ""
    while num > 35:
        txt += jinsu[num % 36]
        num = num // 36
    txt += jinsu[num]
    return txt[::-1]


n = int(input())

texts = []
for i in range(n):
    texts.append(input())

k = int(input())

changedVal = list()

for i in jinsu:
    changedText = 0
    for j in texts:
        changedText += thirtysixtodecimal(j.replace(i, 'Z'))
    changedVal.append(changedText)


for i in range(k):
    pos = 0
    maxs = 0
    for j in range(len(changedVal)):
        if changedVal[j] > maxs:
            maxs = changedVal[j]
            pos = j

    changedVal[pos] = 0
    for j in range(len(texts)):
        texts[j] = texts[j].replace(jinsu[pos], 'Z')
        
maximum = sum(map(thirtysixtodecimal, texts))
print(decimaltothirtysix(maximum))