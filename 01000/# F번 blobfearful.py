# F번
import sys
import copy

def bunhe(x):
    tmpdict = dict()
    while x > 1:
        for i in range(2, x + 1):
            if x % i == 0:
                if i in tmpdict:
                    tmpdict[i] += 1
                else:
                    tmpdict[i] = 1

                x //= i
                break
    return tmpdict

def subdict(x, y):
    tmp = copy.deepcopy(x)
    for i in y:
        if i in tmp:
            tmp[i] = max(tmp[i] - y[i], 0)
            if tmp[i] == 0:
                del tmp[i]
    return tmp

def factorial(x):
    sum = 1
    for i in range(1, x + 1):
        sum *= i
    return sum


k, q = list(map(int, sys.stdin.readline().split(' ')))
arr = list(map(int, sys.stdin.readline().split(' ')))

kdict = bunhe(k)

print(kdict)
print()


for i in arr:
    idict = bunhe(i)
    print(subdict(kdict, idict))
    realdict = subdict(kdict, idict)

    t = realdict.popitem()
    print(t)
    fac = factorial(t[0] * t[1])

    print(bunhe(fac))
    print()








# for i in arr:
#     fac = i
#     j = 1
#     while fac % k != 0:
#         fac *= j
#         j += 1
    
#     print(j-1, end=' ')


# 일단 K를 소인수 분해해서 dict에 넣음
# 