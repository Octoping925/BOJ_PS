// https://www.acmicpc.net/problem/17626
#include <stdio.h>

int dp[50001];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j*j <= i; ++j) {
            if(dp[i] == 0 || dp[i-j*j] + 1 < dp[i]) {
                dp[i] = dp[i-j*j] + 1;
            }
        }
    }

    printf("%d", dp[n]);
}