# https://www.acmicpc.net/problem/3409
import sys

def recursive(num, cnt, arr, K, txt): #dpcbal
    word = arr[num][num]

    if word != 0: # dc
        tmp = 0

        for c in range(cnt, len(txt)):
            if tmp < len(word) and txt[c] == word[tmp]:
                tmp += 1
        return tmp
    
    for i in range(K):

    #left = recursive(num, cnt, arr, K, txt)
    #right = recursive(num, cnt, arr, K, txt)
    #return left + right


testcaseCnt = int(sys.stdin.readline().strip())

for _ in range(testcaseCnt):
    K = int(sys.stdin.readline().strip()) # 방정식(변수)의 개수
    varNames = []
    value = []

    for i in range(K):
        txt = sys.stdin.readline().strip()
        t1, t2 = txt.split(' = ')
        varNames.append(t1)

        if '+' in t2:
            value.append(t2.split(' + '))
        else:
            value.append(t2)
    

    print(varNames)
    print(value)


    # 트리 연결 구조 구하는 2차원 배열 만들기
    arr = [[0 for col in range(K + 1)] for row in range(K + 1)]

    for i in range(K):
        if type(value[i]) == list:
            arr[i][varNames.index(value[i][0])] = 1
            arr[i][varNames.index(value[i][1])] = 2
        else:
            arr[i][i] = value[i]
            

    # print()
    # for i in range(K):
    #     for j in range(K):
    #         print(arr[i][j], end=' ')
    #     print()


    # 트리 탐색하며 P 구하기
    T = sys.stdin.readline().strip() # ROOT 변수 이름
    P = sys.stdin.readline().strip() # 만들어야 하는 변수

    len = recursive(varNames.index(T), 0, arr, K, P)

