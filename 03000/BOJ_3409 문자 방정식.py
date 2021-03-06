# https://www.acmicpc.net/problem/3409
import sys
global arr
global K
global P
global explored

def recursive(nowNode, readCnt):
    WORD = arr[nowNode][0]
    P_LEN = len(P)

    if readCnt == P_LEN or nowNode in explored:
        return readCnt

    explored.append(nowNode)

    if WORD != 0:
        nowReadCnt = 0

        for t in WORD:
            if readCnt + nowReadCnt == P_LEN:
                return readCnt + nowReadCnt

            if P[readCnt + nowReadCnt] == t:
                nowReadCnt += 1
                explored.clear()
        
        return readCnt + nowReadCnt
        

    left = recursive(arr[nowNode][1], readCnt)
    right = recursive(arr[nowNode][2], left)
    return right


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


    # 트리 연결 구조 구하는 2차원 배열 만들기
    arr = [[0 for col in range(3)] for row in range(K)]

    for i in range(K):
        if type(value[i]) == list:
            arr[i][1] = varNames.index(value[i][0])
            arr[i][2] = varNames.index(value[i][1])
        else:
            arr[i][0] = value[i]


    # 트리 탐색하며 P 구하기
    T = sys.stdin.readline().strip() # ROOT 변수 이름
    P = sys.stdin.readline().strip() # 만들어야 하는 변수

    explored = []
    result = recursive(varNames.index(T), 0)

    if result == len(P):
        print('YES')
    else:
        print('NO')

