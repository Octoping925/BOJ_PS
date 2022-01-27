# https://www.acmicpc.net/problem/1339

sum = 0
txt = list()

def recursive(depth, t):
    a=1

n = int(input())

for i in range(n):
    txt.append(input())

    # 브루트 포스로 하나씩 다 넣어보고 최댓값 구하기