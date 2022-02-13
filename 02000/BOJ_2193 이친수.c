// https://www.acmicpc.net/problem/2193
#include <stdio.h>

int n;
long long dp[93][2];

int main()
{
    scanf("%d", &n);
    dp[1][0] = 0, dp[1][1] = 1;
    dp[2][0] = 1, dp[2][1] = 0;
    for(int i = 3; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    printf("%lld", dp[n][0] + dp[n][1]);
}