// https://www.acmicpc.net/problem/2293
#include <stdio.h>

int coin;
int dp[10001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
        
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &coin);
        for(int j = coin; j <= k; ++j) {
            dp[j] += dp[j-coin];
        }
    }

    printf("%d", dp[k]);
}