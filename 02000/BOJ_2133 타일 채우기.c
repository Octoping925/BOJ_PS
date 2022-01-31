// https://www.acmicpc.net/problem/2133
#include <stdio.h>

int dp[33] = { 0, 0, 3, 0, 11, };
int fp[33] = { 0, 0, 1, };
int max = 2;

int func(int x)
{
    if(max >= x) return fp[x];
    fp[x] = dp[x - 4] + func(x-2);
    max = x;
    return fp[x];
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 3; i <= n; ++i)
        dp[i] = dp[i - 2] + 2 * (dp[i - 2] + func(i));
        
    printf("%d", dp[n]);   
}


/*
1가지 방법으로 三을 만들어서 dp(n-2)

2가지 방법으로 L을 만들 수 있음
  - 1가지 방법으로 dp(n-2)
  - 1가지 방법으로 다시 재귀 (2칸 소모됨)

dp(4) = dp(2) + 2* (dp(n-2) + 재귀(4)) = 11

참고로 재귀(1) = 0, 재귀(2) = 1
*/