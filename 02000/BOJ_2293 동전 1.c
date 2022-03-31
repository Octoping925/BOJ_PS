// https://www.acmicpc.net/problem/2293
#include <stdio.h>

int coin;
int dp[10001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= k; ++i)
    {
        scanf("%d", &coin);
        for(int j = 0; j < n; ++j)
        {
            if(i-coin >= 0)
                dp[i] += dp[i-coin];
        }
    }

    printf("%d", dp[k]);
}