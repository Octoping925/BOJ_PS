// https://www.acmicpc.net/problem/2156
#include <stdio.h>
int arr[10010], dp[10010][3];

int max(int x, int y) { return x > y ? x : y; }

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);

    for(int i = 1; i <= n; ++i)
    {
        dp[i][1] = arr[i] + max(max(dp[i - 2][2], dp[i - 2][1]), max(dp[i - 3][2], dp[i - 3][1]));
        dp[i][2] = arr[i] + dp[i - 1][1];
    }

    int m = 0;
    for(int i = 1; i <= n; ++i)
        if(m < max(dp[i][1], dp[i][2])) m = max(dp[i][1], dp[i][2]);
        
    printf("%d", m);
}