// https://www.acmicpc.net/problem/13699
#include <stdio.h>

long long dp[36] = { 1, 1 };

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    
    printf("%lld", dp[n]);

    return 0;
}