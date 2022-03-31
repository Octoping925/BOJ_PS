// https://www.acmicpc.net/problem/15989
#include <stdio.h>

int coin;
int dp[10001];

int main()
{
    int n;
    scanf("%d", &n);
        
    while(n--)
    {
        int k;
        scanf("%d", &k);
        dp[0] = 1;
        for(int i = 1; i <= k; ++i)
            dp[i] = 0;

        for(int i = 1; i <= 3; ++i)  {
            for(int j = 1; j <= k; ++j) {
                if(j-i >= 0)
                    dp[j] += dp[j-i];
            }
        }
        printf("%d\n", dp[k]);
    }
    
}