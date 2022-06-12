// https://www.acmicpc.net/problem/1890
#include <stdio.h>

int map[111][111];
long long dp[111][111];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(map[i][j] == 0) break;
            dp[i + map[i][j]][j] += dp[i][j];
            dp[i][j + map[i][j]] += dp[i][j];
        }
    }

    printf("%lld", dp[n][n]);
    return 0;
}