// https://www.acmicpc.net/problem/14501
#include <stdio.h>

int dp[16], sd[16][2];
int n;

int max(int x, int y) { return x > y ? x : y; }

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &sd[i][0], &sd[i][1]);
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i >= sd[j][0])
            {
                dp[i] = max(dp[i - sd[j][0]] + sd[j][1], dp[i]);
            }
        }
    }

    for(int i = 1; i <=n; ++i) printf("%d ", dp[i]);
    printf("\n");
    printf("%d", dp[n]);
}