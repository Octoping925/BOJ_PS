# https://www.acmicpc.net/problem/23256
global dp
global functmp

def func(x):
    if functmp[x] != 0:
        return functmp[x]

    functmp[x] = (dp[x - 2] + 2 * func(x - 1)) % 1000000007
    return functmp[x]


dp = [0 for _ in range(1000010)]
functmp = [0 for _ in range(1000010)]

dp[1] = 7; dp[2] = 33; dp[3] = 151
functmp[2] = 3; functmp[3] = 13
max = 3

T = int(input())

for mobileentropy in range(T):
    N = int(input())
    if N > max:
        for i in range(max + 1, N + 1):
            dp[i] = (3 * dp[i - 1] + 4 * func(i)) % 1000000007
        
        max = N

    print(dp[N])


#  < 모양으로 끝났을 경우(3가지 방법), dp[n] = dp[n-1] * 지금까지의 경우
#  ◇모양으로 끝났을 경우(7가지 방법), 오직 1가지 방법만 < 모양을 만들 수 있음.
#  2가지 방법으로 다시 ◇모양으로 끝낼 수 있음
#  dp[n] = 3 * dp[n-1] +
#          4 * (1 * dp[n - 2] + 2 * (재귀))