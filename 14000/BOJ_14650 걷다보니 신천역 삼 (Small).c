// https://www.acmicpc.net/problem/14650
#include <stdio.h>

int dp[10][4];
int n;

int main() {
    scanf("%d", &n);
    dp[1][1] = dp[1][2] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i][1] = dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
    }
    printf("%d", dp[n][0]);
}