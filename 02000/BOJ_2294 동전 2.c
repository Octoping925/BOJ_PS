// https://www.acmicpc.net/problem/2293
#include <stdio.h>

int coin[100];
int dp[10001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i)
        scanf("%d", &coin[i]);

    for(int i = 1; i <= k; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i-coin >= 0)
                dp[i] += dp[i-coin];
        }
    }

    printf("%d", dp[k] > 0 ? dp[k] : -1);
}