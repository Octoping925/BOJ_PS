# https://www.acmicpc.net/problem/3409
import sys

testcaseCnt = int(sys.stdin.readline().strip())

for _ in range(testcaseCnt):
    vars = [] # 변수 이름
    exp = []   # 식 넣는 배열
    uncompleted = [] # 미완성된 변수

    K = int(sys.stdin.readline().strip()) # 방정식의 개수

    for i in range(K):
        txt = sys.stdin.readline().strip()
        t1, t2 = txt.split(' = ')
        vars.append(t1)

        if '+' in txt:
            exp.append(t2.split(' + '))
            uncompleted.append(i)
        else:
            exp.append(t2)
    
    T = sys.stdin.readline().strip()

    #print(vars)
    #print(exp)
    #print(uncompleted)
    #print()

    # 문자열들 구하기
    while len(uncompleted) > 0:
        for i in uncompleted:
            if (vars.index(exp[i][0]) not in uncompleted) and (vars.index(exp[i][1]) not in uncompleted):
                exp[i] = f'{exp[vars.index(exp[i][0])]}{exp[vars.index(exp[i][1])]}'
                del uncompleted[uncompleted.index(i)]
                break

    
    #print('####')
    #print(vars)
    #print(exp)
    #print(uncompleted)
    #exit(0)
   

    ###  YESNO체크
    text = exp[vars.index(T)]
    P = sys.stdin.readline().strip()
    del exp
    
    pi = 0

    for c in text:
        if pi < len(P) and c == P[pi]:
            pi += 1
    
    if pi == len(P):
        print('YES')
    else:
        print('NO')



    del pi
    del vars
    del uncompleted

